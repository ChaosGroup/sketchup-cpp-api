require 'yard'

sketchup_api_stubs = Gem.find_files('sketchup-api-stubs').first
raise "sketchup-api-stubs gem is not installed" unless sketchup_api_stubs

YARD::Logger.instance.level = YARD::Logger::ERROR
YARD::Parser::SourceParser.parse(Dir.glob("#{sketchup_api_stubs}/stubs/**/*.rb"))
YARD::Logger.instance.level = YARD::Logger::INFO

YARD::Parser::SourceParser.parse_string(DATA.read)

def method_name_to_cpp(method)
  case method
  when /\?$/ then "is_#{method[0..-2]}"
  when /\=$/ then "set_#{method[0..-2]}"
  else method.to_s
  end
end

def param_type_to_cpp(type)
  case type
  when 'String' then 'const std::string&'
  when 'Integer' then 'long long'
  when 'Float' then 'double'
  when 'Boolean' then 'bool'
  when 'nil' then 'void'
  when 'Array<Sketchup::Drawingelement>' then 'RubyUtils::Enumerable<Sketchup::Drawingelement>'
  when 'Array<Sketchup::Entity, nil>' then 'RubyUtils::Enumerable<std::optional<Sketchup::Drawingelement>>'
  when 'Array<String>' then 'RubyUtils::Enumerable<std::string>'
  when 'Object' then 'RubyUtils::details::IObject'
  when 'Array(Geom::Point3d, Array<Sketchup::Drawingelement>)' then 'RubyUtils::optional<RubyUtils::Enumerable<RubyUtils::tuple<Geom::Point3d DEFINE_WRAPPED_METHOD_COMMA Geom::Vector3d>>>'
  else
    raise "Unsupported type #{type}" unless YARD::Registry.at(type)
    type
  end
end

def param_types_to_cpp(types)
  if type.size == 1
    param_type(types.first)
  elsif type.size == 2 && types.include?(nil)
    "std::optional<#{param_type(types.first)}>"
  else
    "RubyUtils::any_of<#{types.map { |type| param_type_to_cpp(type) }.join(',')}>"
  end
end

def return_type_to_cpp(type)
  param_type_to_cpp(type)
end

def return_types_to_cpp(type)
  param_types_to_cpp(type)
end

[
  # YARD::Registry.at('Sketchup'),
  YARD::Registry.at('Sketchup::Model')
].each { |obj|
  puts "// #{obj.docstring.summary}"
  puts "class #{obj}"
  puts "{"
  obj.constants.each { |constant|
    # todo
  }
  obj.meths.each { |method|
    method_params = method.tags(:param)
    method_return = method.tags(:return).first
    method_overloads = method.tags(:overload)
    signatures = []
    if method_return
      signatures << {
        method: method,
        params: method_params,
        return: method_return
      }
    elsif method_overloads.any?
      method_overloads.each { |overload|
        overload_params = overload.tags(:param).then { |op| op.empty? ? method_params : op}
        overload_return = overload.tags(:return).first || method_return
        signatures << {
          method: method,
          params: overload_params,
          return: overload_return
        }
      }
    else
      raise "Unhandled method #{method}"
    end

    signatures.each { |signature|
      arg0 = return_type_to_cpp(signature[:return].type)
      puts "  DEFINE_WRAPPED_METHOD_0(#{arg0})"
    }

  }
  puts "}"
}

__END__

class Sketchup::Model

  # @return [String] name
  def name=(name)
  end

end
