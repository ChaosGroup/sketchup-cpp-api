class APIInterface

  SUPPORTED_OBJECTS = [
    'Sketchup::Model'
  ]

  def self.setup
    ruby_files = Dir.glob("#{__dir__}/ruby-api-stubs/lib/sketchup-api-stubs/stubs/**/*.rb")
    YARD::Logger.instance.level = YARD::Logger::ERROR
    YARD::Parser::SourceParser.parse(ruby_files)
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