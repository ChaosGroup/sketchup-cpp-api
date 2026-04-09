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
    s << doc_comment(indentation)
    s << "#{indentation}namespace #{@module_object.path}" << "\n"
    s << "#{indentation}{" << "\n"
    method_interfaces.each { |interface|
      s << interface.definition("#{indentation}\t") << "\n"
    }
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
