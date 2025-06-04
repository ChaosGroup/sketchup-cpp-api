require 'yard'

class MethodSignature

  def initialize(method, overload = nil)
    @method = method
    @params = overload&.tags(:param) || method.tags(:param)
    @return = overload&.tags(:return)&.first || method.tags(:return).first
    raise "No return for #{method} #{overload}" if @return.nil?
  end

  def declaration(spaces:)
    s = ''
    function = method_to_cpp(@method)
    method = @method.name.to_s.gsub("=", " =") # TODO drop gsub
    ret = return_to_cpp(@return)
    if @params.empty?
      s << ' ' * spaces << "DEFINE_WRAPPED_METHOD_0(#{ret}, #{function}, #{method})"
    else
      function_args = @params.map { |param, default|
        "#{type_to_cpp(param.type)} #{param.name}"
        puts "@@#{default}" if method == 'place_component'
      }
      method_args = @params.map { |param| param.name }
      s << ' ' * spaces << "DEFINE_WRAPPED_METHOD(#{ret}, #{function}, (#{function_args.join(', ')}), #{method}, #{method_args.join(', ')})"
    end
  end

  def method_to_cpp(method_tag)
    method = method_tag.name.to_s
    case method
    when /\?$/ then "is_#{method[0..-2]}"
    when /\=$/ then "set_#{method[0..-2]}"
    when 'export'then "export_"
    when 'import'then "import_"
    else method
    end
  end

  def return_to_cpp(return_tag)
    types = return_tag.types
    if types.size == 1
      type_to_cpp(types.first)
    elsif types.size == 2 && types.include?('nil')
      "RubyUtils::optional<#{type_to_cpp(types.find(&:itself))}>"
    else
      "RubyUtils::any_of<#{types.map { |type| type_to_cpp(type) }.join(', ')}>"
    end
  end

  def type_to_cpp(type)
    case type
    when 'String' then 'std::string' #'const std::string&'
    when 'Integer' then 'long long'
    when 'Float', 'Numeric' then 'double'
    when 'Boolean' then 'bool'
    when 'nil' then 'void'
    when 'Array<Sketchup::Drawingelement>' then 'RubyUtils::Enumerable<Sketchup::Drawingelement>'
    when 'Array<Sketchup::Entity, nil>' then 'RubyUtils::Enumerable<RubyUtils::optional<Sketchup::Drawingelement>>'
    when 'Array(Numeric, Numeric)' then 'std::tupple<double, double>'
    when 'Array(Geom::Point3d, Geom::Point3d)' then 'std::tupple<Geom::Point3d, Geom::Point3d>'
    when 'Array(Geom::Point3d, Geom::Vector3d)' then 'std::tupple<Geom::Vector3d, Geom::Vector3d>'
    when 'Array<String>' then 'RubyUtils::Enumerable<std::string>'
    when 'Object' then 'RubyUtils::details::IObject'
    when 'Array(Geom::Point3d, Array<Sketchup::Drawingelement>)' then 'RubyUtils::optional<RubyUtils::Enumerable<RubyUtils::tuple<Geom::Point3d DEFINE_WRAPPED_METHOD_COMMA Geom::Vector3d>>>'
    when 'Hash' then 'TODO'
    else
      raise "Unsupported type #{type} for #{@method}" unless YARD::Registry.at(type)
      type
    end
  end

end

class MethodInterface

  def initialize(method)
    @method = method
    @signatures = signatures(method)
    raise "No signature found for #{method}" if @signatures.empty?
  end

  def declaration(spaces: 0)
    s = ''
    @signatures.each { |signature|
      s << "#{signature.declaration(spaces: spaces)}\n"
    }
    s
  end

  private

  def signatures(method)
    method_overloads = method.tags(:overload)
    if method_overloads.empty?
      [MethodSignature.new(method)]
    else
      method_overloads.map { |overload|
        MethodSignature.new(method, overload)
      }
    end
  end

end

class ObjectInterface

  attr_reader :method_interfaces

  def initialize(object)
    @object = object
    @method_interfaces = @object.meths.map { |method| MethodInterface.new(method) }
  end

  def declaration
    s = ''
    s << "// #{@object.docstring.summary}"
    s << "class #{@object}\n"
    s << "{\n"
    method_interfaces.each { |method_interface|
      s << "#{method_interface.declaration}"
    }
    s << "\n"
    s << "}\n"
  end

end

class APIInterface

  SUPPORTED_OBJECTS = [
    'Sketchup::Model'
  ]

  def self.setup(gem = 'sketchup-api-stubs')
    sketchup_api_stubs = Gem.find_files('sketchup-api-stubs').first
    raise "sketchup-api-stubs gem is not installed" unless sketchup_api_stubs
    YARD::Logger.instance.level = YARD::Logger::ERROR
    YARD::Parser::SourceParser.parse(Dir.glob("#{sketchup_api_stubs}/stubs/**/*.rb"))
    YARD::Parser::SourceParser.parse_string(DATA.read) # Complement with additional data
    YARD::Logger.instance.level = YARD::Logger::INFO
  end

  def self.each
    return enum_for(:each) unless block_given?
    SUPPORTED_OBJECTS.each { |object|
      yield ObjectInterface.new(YARD::Registry.at(object))
    }
  end

end

APIInterface.setup('sketchup-api-stubs')
APIInterface.each { |obj_generator|
  puts obj_generator.declaration
}

__END__

class Sketchup::Model

  # @return [String] name
  def name=(name)
  end

  # @param [String] name
  # @return [nil]
  def find_entity_by_id(ids_or_array)
  end

  # @param [String] name
  # @return [nil]
  def find_entity_by_persistent_id(ids_or_array)
  end

end
