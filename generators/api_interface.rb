class APIInterface

  SUPPORTED_OBJECTS = [
    'Sketchup::Model'
  ]

  def self.setup(gem = 'sketchup-api-stubs')
    sketchup_api_stubs = Gem.find_files('sketchup-api-stubs').first # TODO Add submodule
    raise "sketchup-api-stubs gem is not installed" unless sketchup_api_stubs
    YARD::Logger.instance.level = YARD::Logger::ERROR
    YARD::Parser::SourceParser.parse(Dir.glob("#{sketchup_api_stubs}/stubs/**/*.rb"))
    # YARD::Parser::SourceParser.parse_string(DATA.read) # TODO add override file
    YARD::Logger.instance.level = YARD::Logger::INFO
  end

  def self.export(path)
    File.write("#{path}/hostapp.hpp", hpp)
  end

  def self.hpp
    s = ''
    s << "#include <ruby.h>" << "\n\n"

    s << "namespace sca" << "\n"
    s << "{" << "\n"
    s << "\tnamespace HostApp" << "\n"
    s << "\t{" << "\n"

    namespaced_classes = []

    YARD::Registry.all(:module).each { |entry|
      s << "\t\tnamespace #{entry.path}" << "\n"
      s << "\t\t{" << "\n"
      entry.children.select { |c| c.type == :class }.each { |child|
        namespaced_classes << child
        s << "\t\t\tclass #{child.name};" << "\n"
      }
      s << "\t\t}" << "\n"
    }

    (YARD::Registry.all(:class) - namespaced_classes).each { |entry|
      s << "\t\tclass #{entry.name};" << "\n"
    }
    s << "\t}" << "\n"
    s << "}" << "\n"

    s
  end

  def self.each
    return enum_for(:each) unless block_given?
    SUPPORTED_OBJECTS.each { |object|
      yield ObjectInterface.new(YARD::Registry.at(object))
    }
  end

end