require_relative 'method_interface'

class ModuleInterface

  def initialize(module_object)
    @module_object = module_object
  end

  def forward_declaration(indentation = '')
    "#{indentation}namespace #{@module_object.path} {}"
  end

  def definition(indentation = '')
    method_interfaces = @module_object.meths.map { |meth| MethodInterface.new(meth) }
    s = ''
    s << "#{indentation}namespace #{@module_object.path}" << "\n"
    s << "#{indentation}{" << "\n"
    method_interfaces.each { |interface|
      s << interface.definition("#{indentation}\t") << "\n"
    }
    s << "#{indentation}}"
    s
  end

end
