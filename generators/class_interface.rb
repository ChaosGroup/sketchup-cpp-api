class ClassInterface

  def initialize(class_object)
    @class_object = class_object
  end

  def forward_declare
    namespace = @class_object.namespace
    if namespace.root?
      "class #{@class_object.path};"
    else
      "namespace #{namespace.name} { class #{@class_object.name}; }"
    end
  end
  
end
