require_relative 'class_interface'
require_relative 'module_interface'

class APIInterface

  def self.setup
    ruby_files = Dir.glob("#{__dir__}/ruby-api-stubs/lib/sketchup-api-stubs/stubs/**/*.rb")
    ruby_override = "#{__dir__}/api_override.rb"
    YARD::Logger.instance.level = YARD::Logger::ERROR
    YARD::Parser::SourceParser.parse(ruby_files)
    YARD::Parser::SourceParser.parse([ruby_override])
    YARD::Logger.instance.level = YARD::Logger::INFO
  end

  def self.export(path)
    File.write("#{path}/hostapp.hpp", hpp)
  end

  def self.hpp
    s = ''
    s << '#pragma once' << "\n"
    s << "\n"
    s << '#ifndef SKETCHUP_VERSION' << "\n"
    s << '#error "SKETCHUP_VERSION must be defined"' << "\n"
    s << '#endif' << "\n"
    s << "\n"
    s << '#include <ruby.h>' << "\n"
    s << '#include <string>' << "\n"
    s << '#include <vector>' << "\n"
    s << '#include <map>' << "\n"
    s << '#include <optional>' << "\n"
    s << '#include <variant>' << "\n"
    s << '#include <type_traits>' << "\n"
    s << '#include <stdexcept>' << "\n\n"

    s << "namespace sca" << "\n"
    s << "{" << "\n"
    s << "\n"
    s << "\tclass Object" << "\n"
    s << "\t{" << "\n"
    s << "\tpublic:" << "\n"
    s << "\t\tVALUE self = Qnil;" << "\n"
    s << "\t\tObject() = default;" << "\n"
    s << "\t\tObject(VALUE v) : self(v) {}" << "\n"
    s << "\t};" << "\n"
    s << "\n"

    # to_ruby: convert C++ values to Ruby VALUE
    s << "\tinline VALUE to_ruby(bool v) { return v ? Qtrue : Qfalse; }" << "\n"
    s << "\tinline VALUE to_ruby(long v) { return LONG2NUM(v); }" << "\n"
    s << "\tinline VALUE to_ruby(double v) { return DBL2NUM(v); }" << "\n"
    s << "\tinline VALUE to_ruby(const char* v) { return rb_str_new_cstr(v); }" << "\n"
    s << "\tinline VALUE to_ruby(const std::string& v) { return rb_str_new_cstr(v.c_str()); }" << "\n"
    s << "\ttemplate<typename T> requires requires(T t) { t.self; }" << "\n"
    s << "\tinline VALUE to_ruby(const T& v) { return v.self; }" << "\n"
    s << "\n"

    # from_ruby: type traits for optional/vector/variant
    s << "\ttemplate<typename T> struct is_optional : std::false_type {};" << "\n"
    s << "\ttemplate<typename T> struct is_optional<std::optional<T>> : std::true_type {};" << "\n"
    s << "\ttemplate<typename T> struct is_vector : std::false_type {};" << "\n"
    s << "\ttemplate<typename T> struct is_vector<std::vector<T>> : std::true_type {};" << "\n"
    s << "\ttemplate<typename T> struct is_variant : std::false_type {};" << "\n"
    s << "\ttemplate<typename... Ts> struct is_variant<std::variant<Ts...>> : std::true_type {};" << "\n"
    s << "\n"

    # from_ruby: convert Ruby VALUE to C++ type
    s << "\ttemplate<typename T>" << "\n"
    s << "\tinline T from_ruby(VALUE val)" << "\n"
    s << "\t{" << "\n"
    s << "\t\tif constexpr (is_optional<T>::value) {" << "\n"
    s << "\t\t\tif (val == Qnil) return std::nullopt;" << "\n"
    s << "\t\t\treturn from_ruby<typename T::value_type>(val);" << "\n"
    s << "\t\t}" << "\n"
    s << "\t\telse if constexpr (is_vector<T>::value) {" << "\n"
    s << "\t\t\tlong len = RARRAY_LEN(val);" << "\n"
    s << "\t\t\tT result;" << "\n"
    s << "\t\t\tresult.reserve(len);" << "\n"
    s << "\t\t\tfor (long i = 0; i < len; i++)" << "\n"
    s << "\t\t\t\tresult.push_back(from_ruby<typename T::value_type>(rb_ary_entry(val, i)));" << "\n"
    s << "\t\t\treturn result;" << "\n"
    s << "\t\t}" << "\n"
    s << "\t\telse if constexpr (is_variant<T>::value) {" << "\n"
    s << "\t\t\treturn T{};" << "\n"
    s << "\t\t}" << "\n"
    s << "\t\telse if constexpr (std::is_same_v<T, bool>) return RTEST(val);" << "\n"
    s << "\t\telse if constexpr (std::is_same_v<T, long>) return NUM2LONG(val);" << "\n"
    s << "\t\telse if constexpr (std::is_same_v<T, double>) return NUM2DBL(val);" << "\n"
    s << "\t\telse if constexpr (std::is_same_v<T, std::string>) return std::string(StringValueCStr(val));" << "\n"
    s << "\t\telse if constexpr (std::is_same_v<T, const char*>) return rb_id2name(SYM2ID(val));" << "\n"
    s << "\t\telse return T(val);" << "\n"
    s << "\t}" << "\n"
    s << "\n"

    # ruby_error exception and protect() wrapper
    s << "\tstruct ruby_error : std::runtime_error {" << "\n"
    s << "\t\tusing std::runtime_error::runtime_error;" << "\n"
    s << "\t};" << "\n"
    s << "\n"
    s << "\ttemplate<typename Fn>" << "\n"
    s << "\tinline auto protect(Fn fn) -> decltype(fn())" << "\n"
    s << "\t{" << "\n"
    s << "\t\tusing R = decltype(fn());" << "\n"
    s << "\t\tif constexpr (std::is_void_v<R>) {" << "\n"
    s << "\t\t\tint state = 0;" << "\n"
    s << "\t\t\trb_protect([](VALUE data) -> VALUE {" << "\n"
    s << "\t\t\t\t(*reinterpret_cast<Fn*>(data))();" << "\n"
    s << "\t\t\t\treturn Qnil;" << "\n"
    s << "\t\t\t}, reinterpret_cast<VALUE>(&fn), &state);" << "\n"
    s << "\t\t\tif (state) {" << "\n"
    s << "\t\t\t\tVALUE err = rb_errinfo();" << "\n"
    s << "\t\t\t\trb_set_errinfo(Qnil);" << "\n"
    s << "\t\t\t\tVALUE msg = rb_obj_as_string(err);" << "\n"
    s << "\t\t\t\tthrow ruby_error(std::string(StringValueCStr(msg)));" << "\n"
    s << "\t\t\t}" << "\n"
    s << "\t\t} else {" << "\n"
    s << "\t\t\tR result{};" << "\n"
    s << "\t\t\tstruct Ctx { Fn* fn; R* out; };" << "\n"
    s << "\t\t\tCtx ctx{&fn, &result};" << "\n"
    s << "\t\t\tint state = 0;" << "\n"
    s << "\t\t\trb_protect([](VALUE data) -> VALUE {" << "\n"
    s << "\t\t\t\tauto* c = reinterpret_cast<Ctx*>(data);" << "\n"
    s << "\t\t\t\t*(c->out) = (*(c->fn))();" << "\n"
    s << "\t\t\t\treturn Qnil;" << "\n"
    s << "\t\t\t}, reinterpret_cast<VALUE>(&ctx), &state);" << "\n"
    s << "\t\t\tif (state) {" << "\n"
    s << "\t\t\t\tVALUE err = rb_errinfo();" << "\n"
    s << "\t\t\t\trb_set_errinfo(Qnil);" << "\n"
    s << "\t\t\t\tVALUE msg = rb_obj_as_string(err);" << "\n"
    s << "\t\t\t\tthrow ruby_error(std::string(StringValueCStr(msg)));" << "\n"
    s << "\t\t\t}" << "\n"
    s << "\t\t\treturn result;" << "\n"
    s << "\t\t}" << "\n"
    s << "\t}" << "\n"
    s << "\n"

    s << "\tnamespace HostApp" << "\n"
    s << "\t{" << "\n"

    module_interfaces = YARD::Registry.all(:module).map { |element| ModuleInterface.new(element) }
    class_interfaces = YARD::Registry.all(:class).map { |element| ClassInterface.new(element) }
    main_indentation = "\t\t"

    module_interfaces.each { |interface|
      s << interface.forward_declaration(main_indentation) << "\n"
    }

    class_interfaces.each { |interface|
      s << interface.forward_declaration(main_indentation) << "\n"
    }

    class_interfaces.each { |interface|
      s << interface.definition(main_indentation) << "\n"
    }

    module_interfaces.each { |interface|
      s << interface.definition(main_indentation) << "\n"
    }

    s << "\t}" << "\n"
    s << "}" << "\n"

    s
  end

end
