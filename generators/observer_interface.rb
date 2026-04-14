require_relative 'method_interface'

class ObserverInterface

  # Maps host class/module path -> observer class path
  OBSERVER_MAP = {
    'Sketchup' => 'Sketchup::AppObserver',
    'Sketchup::Model' => 'Sketchup::ModelObserver',
    'Sketchup::Entities' => 'Sketchup::EntitiesObserver',
    'Sketchup::Entity' => 'Sketchup::EntityObserver',
    'Sketchup::Selection' => 'Sketchup::SelectionObserver',
    'Sketchup::View' => 'Sketchup::ViewObserver',
    'Sketchup::Tools' => 'Sketchup::ToolsObserver',
    'Sketchup::Materials' => 'Sketchup::MaterialsObserver',
    'Sketchup::DefinitionList' => 'Sketchup::DefinitionsObserver',
    'Sketchup::ComponentDefinition' => 'Sketchup::DefinitionObserver',
    'Sketchup::ComponentInstance' => 'Sketchup::InstanceObserver',
    'Sketchup::Pages' => 'Sketchup::PagesObserver',
    'Sketchup::Layers' => 'Sketchup::LayersObserver',
    'Sketchup::RenderingOptions' => 'Sketchup::RenderingOptionsObserver',
    'Sketchup::OptionsProvider' => 'Sketchup::OptionsProviderObserver',
    'Sketchup::ShadowInfo' => 'Sketchup::ShadowInfoObserver',
    'Sketchup::Dimension' => 'Sketchup::DimensionObserver',
    'Sketchup::Environments' => 'Sketchup::EnvironmentsObserver',
    'Sketchup::Group' => 'Sketchup::EntityObserver',
  }.freeze

  def self.observer?(class_object)
    class_object.has_tag?(:abstract) && class_object.name.to_s.end_with?('Observer')
  end

  def self.observer_for(host_path)
    OBSERVER_MAP[host_path]
  end

  def initialize(class_object)
    @class_object = class_object
    @methods = class_object.meths(inherited: false, included: false)
      .select { |m| m.scope == :instance }
  end

  def observer_name
    @class_object.name.to_s
  end

  def full_path
    @class_object.path
  end

  def ruby_class_name
    @class_object.path
  end

  def parent_observer
    sup = @class_object.superclass
    return nil if sup.nil? || sup.path == 'Object' || sup == YARD::Registry.root
    return nil unless ObserverInterface.observer?(sup)
    ObserverInterface.new(sup)
  end

  # Phase 2: Observer class definition with protected virtual methods
  def class_definition(indentation)
    name = @class_object.name.to_s
    namespace = @class_object.namespace
    ruby_path = @class_object.path

    # Build superclass clause
    parent = parent_observer
    superclass_clause = parent ? " : public #{parent.full_path}" : ""

    lines = []
    lines << "#{indentation}namespace #{namespace.path} {"
    lines << "#{indentation}\tclass #{name}#{superclass_clause} {"
    lines << "#{indentation}\tpublic:"
    lines << "#{indentation}\t\tVALUE self = Qnil;"
    lines << "#{indentation}\t\tstatic constexpr const char* ruby_class_name = \"#{ruby_path}\";"
    lines << "#{indentation}\t\tvirtual ~#{name}() = default;"
    lines << "#{indentation}\t\t#{name}(VALUE v) : self(v) {}"
    lines << "#{indentation}\tprotected:"
    lines << "#{indentation}\t\t#{name}() = default;"

    @methods.each do |meth|
      ret = observer_return_type(meth)
      params = observer_params(meth)
      param_list = params.map { |p| "#{p[:cpp_type]} /*#{p[:name]}*/" }.join(', ')
      if ret == 'void'
        lines << "#{indentation}\t\tvirtual void #{meth.name}(#{param_list}) {}"
      else
        lines << "#{indentation}\t\tvirtual #{ret} #{meth.name}(#{param_list}) { return {}; }"
      end
    end

    lines << "#{indentation}\t};"
    lines << "#{indentation}}"
    lines.join("\n")
  end

  # Phase 4: Concepts, trampolines, and register function
  def infrastructure(indentation)
    obs_name = observer_name
    lines = []

    # Concepts
    @methods.each do |meth|
      params = observer_params(meth)
      param_decls = params.map { |p| "#{p[:cpp_type]} #{p[:name]}" }.join(', ')
      args = params.map { |p| p[:name] }.join(', ')
      call_expr = args.empty? ? "t.#{meth.name}()" : "t.#{meth.name}(#{args})"
      lines << "#{indentation}template<typename T>"
      lines << "#{indentation}concept #{obs_name}_has_#{meth.name} = requires(T& t#{params.empty? ? '' : ', ' + param_decls}) { #{call_expr}; };"
      lines << ""
    end

    # Trampolines
    @methods.each do |meth|
      params = observer_params(meth)
      ret = observer_return_type(meth)
      argc = params.size

      value_params = (0...argc).map { |i| "VALUE a#{i}" }.join(', ')
      func_params = "VALUE self#{argc > 0 ? ', ' + value_params : ''}"

      lines << "#{indentation}template<typename T>"
      lines << "#{indentation}VALUE #{obs_name}_trampoline_#{meth.name}(#{func_params}) {"
      lines << "#{indentation}\tstd::shared_ptr<T>* sp;"
      lines << "#{indentation}\tData_Get_Struct(self, std::shared_ptr<T>, sp);"

      # Convert arguments
      params.each_with_index do |p, i|
        lines << "#{indentation}\tauto cpp_a#{i} = SketchUpCppAPI::from_ruby<#{p[:cpp_type]}>(a#{i});"
      end

      cpp_args = (0...argc).map { |i| "cpp_a#{i}" }.join(', ')
      if ret == 'void'
        lines << "#{indentation}\t(*sp)->#{meth.name}(#{cpp_args});"
        lines << "#{indentation}\treturn Qnil;"
      else
        lines << "#{indentation}\tauto result = (*sp)->#{meth.name}(#{cpp_args});"
        lines << "#{indentation}\treturn SketchUpCppAPI::to_ruby(result);"
      end

      lines << "#{indentation}}"
      lines << ""
    end

    # Register function
    lines << "#{indentation}template<typename T>"
    lines << "#{indentation}void register_#{obs_name}(VALUE klass) {"

    # Call parent register function if this observer inherits from another
    parent = parent_observer
    if parent
      lines << "#{indentation}\tregister_#{parent.observer_name}<T>(klass);"
    end

    @methods.each do |meth|
      argc = observer_params(meth).size
      lines << "#{indentation}\tif constexpr (#{obs_name}_has_#{meth.name}<T>)"
      lines << "#{indentation}\t\trb_define_method(klass, \"#{meth.name}\", RUBY_METHOD_FUNC(#{obs_name}_trampoline_#{meth.name}<T>), #{argc});"
    end

    lines << "#{indentation}}"

    lines.join("\n")
  end

  # Phase 5: add_observer out-of-class definition for a class
  def add_observer_definition(host_class_path, indentation, is_module: false)
    obs_name = observer_name
    obs_path = full_path
    lines = []

    if is_module
      # Module-level (static) add_observer - e.g., Sketchup.add_observer
      lines << "#{indentation}template<typename T> requires std::derived_from<T, #{obs_path}>"
      lines << "#{indentation}static bool add_observer(std::shared_ptr<T>& observer) {"
      lines << "#{indentation}\tif (observer->self == Qnil) {"
      lines << "#{indentation}\t\tdetail::init_observer(observer, [](VALUE klass) { detail::register_#{obs_name}<T>(klass); });"
      lines << "#{indentation}\t}"
      lines << "#{indentation}\treturn SketchUpCppAPI::from_ruby<bool>(rb_funcall(rb_eval_string(\"#{host_class_path}\"), rb_intern(\"add_observer\"), 1, observer->self));"
      lines << "#{indentation}}"
      lines << ""
      lines << "#{indentation}template<typename T> requires std::derived_from<T, #{obs_path}>"
      lines << "#{indentation}static bool remove_observer(std::shared_ptr<T>& observer) {"
      lines << "#{indentation}\tif (observer->self == Qnil) return false;"
      lines << "#{indentation}\treturn SketchUpCppAPI::from_ruby<bool>(rb_funcall(rb_eval_string(\"#{host_class_path}\"), rb_intern(\"remove_observer\"), 1, observer->self));"
      lines << "#{indentation}}"
    else
      # Instance method add_observer - e.g., model.add_observer
      # Out-of-class definition
      ns_parts = host_class_path.split('::')
      class_name = ns_parts.pop
      ns = ns_parts.join('::')

      lines << "#{indentation}namespace #{ns} {"
      lines << "#{indentation}\ttemplate<typename T> requires std::derived_from<T, #{obs_path}>"
      lines << "#{indentation}\tinline bool #{class_name}::add_observer(std::shared_ptr<T>& observer) {"
      lines << "#{indentation}\t\tif (observer->self == Qnil) {"
      lines << "#{indentation}\t\t\tdetail::init_observer(observer, [](VALUE klass) { detail::register_#{obs_name}<T>(klass); });"
      lines << "#{indentation}\t\t}"
      lines << "#{indentation}\t\treturn SketchUpCppAPI::from_ruby<bool>(rb_funcall(self, rb_intern(\"add_observer\"), 1, observer->self));"
      lines << "#{indentation}\t}"
      lines << ""
      lines << "#{indentation}\ttemplate<typename T> requires std::derived_from<T, #{obs_path}>"
      lines << "#{indentation}\tinline bool #{class_name}::remove_observer(std::shared_ptr<T>& observer) {"
      lines << "#{indentation}\t\tif (observer->self == Qnil) return false;"
      lines << "#{indentation}\t\treturn SketchUpCppAPI::from_ruby<bool>(rb_funcall(self, rb_intern(\"remove_observer\"), 1, observer->self));"
      lines << "#{indentation}\t}"
      lines << "#{indentation}}"
    end

    lines.join("\n")
  end

  # add_observer/remove_observer declarations to go inside the class body
  def add_observer_declaration(indentation)
    obs_path = full_path
    lines = []
    lines << "#{indentation}template<typename T> requires std::derived_from<T, #{obs_path}>"
    lines << "#{indentation}bool add_observer(std::shared_ptr<T>& observer);"
    lines << "#{indentation}template<typename T> requires std::derived_from<T, #{obs_path}>"
    lines << "#{indentation}bool remove_observer(std::shared_ptr<T>& observer);"
    lines.join("\n")
  end

  private

  def observer_params(meth)
    meth.parameters.map do |param|
      pname = param[0].to_s.gsub('*', '')
      tag = meth.tags.select { |t| t.tag_name == 'param' && t.name == pname }.first
      ruby_type = tag&.types&.first
      cpp_type = ruby_type ? observer_cpp_type(ruby_type) : 'VALUE'
      { name: pname, cpp_type: cpp_type }
    end
  end

  def observer_return_type(meth)
    tag = meth.tags.find { |t| t.tag_name == 'return' }
    return 'void' unless tag && tag.types
    types = tag.types.reject { |t| t == 'nil' || t == 'NilClass' }
    return 'void' if types.empty?
    types.size == 1 ? observer_cpp_type(types.first) : 'void'
  end

  def observer_cpp_type(ruby_type)
    case ruby_type
    when 'NilClass', 'nil' then 'void'
    when 'Integer' then 'long'
    when 'Float' then 'double'
    when 'String' then 'std::string'
    when 'Symbol' then 'const char*'
    when 'TrueClass', 'FalseClass', 'Boolean', 'false' then 'bool'
    else ruby_type
    end
  end

end
