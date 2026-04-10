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
    File.write(path, hpp)
  end

  def self.hpp
    s = ''
    s << '#pragma once' << "\n"
    s << "\n"
    s << '#ifndef SKETCHUP_VERSION' << "\n"
    s << '#error "SKETCHUP_VERSION must be defined"' << "\n"
    s << '#endif' << "\n"
    s << "\n"

    s << "namespace SketchUpCppAPI::HostApp" << "\n"
    s << "{" << "\n"

    module_interfaces = YARD::Registry.all(:module).map { |element| ModuleInterface.new(element) }
    class_interfaces = YARD::Registry.all(:class).map { |element| ClassInterface.new(element) }
    main_indentation = "\t"

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

    s << "}" << "\n"

    s
  end

end
