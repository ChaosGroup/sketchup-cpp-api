class MethodInterface

  def initialize(method_object)
    @method_object = method_object
  end

  def forward_declaration(indentation = '')
    s << "#{indentation}#{function_prefix}#{function_retval} #{function_name}(#{function_args})" << "\n"
  end

  def definition(indentation = '')
    retval = function_retval
    body = if retval == 'void' then ''
           elsif retval == 'auto' then 'return 0;'
           else 'return {};'
           end
    s = ''
    s << "#{indentation}#{function_prefix}#{retval} #{function_name}(#{function_args})" << "\n"
    s << "#{indentation}{" << "\n"
    s << "#{indentation}\t#{body}" << "\n"
    s << "#{indentation}}"
    s
  end

  private

  def function_prefix
    @method_object.scope == :class ? "static " : ""
  end

  def function_retval
    tag = @method_object.tags.find { |t| t.tag_name == 'return' }
    if tag && tag.types
      cpp_types(tag.types)
    else
      'void' # fallback if no @return
    end
  end

  def function_name
    name = @method_object.name.to_s
    return 'operator==' if name == '=='
    return 'get_template' if name == 'template'
    return "#{name.chop}" if name.end_with?('?')
    return "assign_#{name.chop}" if name.end_with?('=')
    name
  end

  def function_args
    @method_object.parameters.map { |param|
      function_param(param)
    }.join(", ")
  end

  def function_param(param)
    pname = param[0].to_s.gsub('*', '')
    default = param[1] ? " = #{param[1]}" : ''
    "auto _#{pname}_"
  end

  def cpp_type(ruby_type)
    case ruby_type
    when 'NilClass', 'nil' then 'void'
    when 'Integer' then 'int'
    when 'Float' then 'double'
    when 'String' then 'std::string'
    when 'Symbol' then 'const char*'
    when 'TrueClass', 'FalseClass', 'Boolean', 'false' then 'bool'
    when 'Array' then 'std::vector<auto>'
    when 'Array(Geom::Point3d, Geom::Point3d)' then 'std::pair<Geom::Point3d, Geom::Point3d>'
    when 'Array(Geom::Point3d, Geom::Vector3d)' then 'std::pair<Geom::Point3d, Geom::Vector3d>'
    when 'Array<String>' then 'std::vector<std::string>'
    when 'Array<Geom::Point3d>' then 'std::vector<Geom::Point3d>'
    when 'Hash' then 'std::map<auto, auto>'
    when 'Module' then 'auto'
    when 'Object' then 'Object'
    else 
      raise "Unhandled type #{ruby_type}" unless YARD::Registry.at(ruby_type.to_s)
      ruby_type
    end
  end

  def cpp_types(ruby_types)
    case ruby_types.size
    when 0 then 'void'
    when 1 then cpp_type(ruby_types.first)
    else
      types = ruby_types.map { |type| cpp_type(type) }
      void_type = types.delete('void')
      if types.size == 1 && void_type
        "std::optional<#{types.first}>"
      else
        "std::variant<#{types.join(', ')}#{}>"
      end
    end
  end

end
