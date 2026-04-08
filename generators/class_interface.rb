class ClassInterface

  def initialize(class_object)
    @class_object = class_object
  end

  def forward_declaration(indentation = '')
    namespace = @class_object.namespace
    if namespace.root?
      "#{indentation}class #{@class_object.path};"
    else
      "#{indentation}namespace #{namespace.path} { class #{@class_object.name}; }"
    end
  end

  def definition(indentation = '')
    namespace = @class_object.namespace
    if namespace.root?
      "#{indentation}class #{@class_object.path} {};"
    else
      "#{indentation}namespace #{namespace.path} { class #{@class_object.name} {}; }"
    end
  end

end
