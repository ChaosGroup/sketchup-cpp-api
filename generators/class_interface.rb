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
    name = @class_object.name
    namespace = @class_object.namespace
    body = "public: VALUE self = Qnil; #{name}() = default; #{name}(VALUE v) : self(v) {}"
    if namespace.root?
      "#{indentation}class #{@class_object.path} { #{body} };"
    else
      "#{indentation}namespace #{namespace.path} { class #{name} { #{body} }; }"
    end
  end

end
