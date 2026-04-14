require_relative 'method_interface'
require_relative 'observer_interface'

class ModuleInterface

  def initialize(module_object)
    @module_object = module_object
  end

  def forward_declaration(indentation = '')
    "#{indentation}namespace #{@module_object.path} {}"
  end

  def definition(indentation = '', observer_classes = [])
    method_interfaces = @module_object.meths.map { |meth| MethodInterface.new(meth) }
    # Check if this module hosts an observer
    observer_path = ObserverInterface.observer_for(@module_object.path)
    observer = observer_classes.find { |o| o.full_path == observer_path } if observer_path

    s = ''
    s << doc_comment(indentation)
    s << "#{indentation}namespace #{@module_object.path}" << "\n"
    s << "#{indentation}{" << "\n"
    method_interfaces.each { |interface|
      method_name = interface.instance_variable_get(:@method_object).name.to_s
      # Skip auto-generated add_observer/remove_observer if we have a typed version
      if observer && (method_name == 'add_observer' || method_name == 'remove_observer')
        next
      end
      s << interface.definition("#{indentation}\t") << "\n"
    }
    # Add typed observer methods if this module hosts an observer
    if observer
      s << observer.add_observer_definition(@module_object.path, "#{indentation}\t", is_module: true) << "\n"
    end
    s << "#{indentation}}"
    s
  end

  private

  def doc_comment(indentation)
    lines = []
    doc = @module_object.docstring.to_s
    unless doc.empty?
      doc.each_line do |line|
        break if line.strip.start_with?('@')
        lines << line.rstrip
      end
      lines.pop while lines.last&.strip&.empty?
    end

    return '' if lines.empty?

    s = "#{indentation}/**\n"
    lines.each { |line| s << "#{indentation} * #{line}\n" }
    s << "#{indentation} */\n"
    s
  end

end
