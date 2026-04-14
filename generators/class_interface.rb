require_relative 'observer_interface'

class ClassInterface

  def initialize(class_object)
    @class_object = class_object
  end

  def observer?
    ObserverInterface.observer?(@class_object)
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
    if observer?
      ObserverInterface.new(@class_object).class_definition(indentation)
    else
      standard_definition(indentation)
    end
  end

  private

  def standard_definition(indentation)
    name = @class_object.name
    namespace = @class_object.namespace
    body = "public: VALUE self = Qnil; #{name}() = default; #{name}(VALUE v) : self(v) {}"

    # Check if this class hosts an observer (has add_observer method)
    observer_path = ObserverInterface.observer_for(@class_object.path)
    if observer_path
      body += "; #{add_observer_declarations(observer_path)}"
    end

    if namespace.root?
      "#{indentation}class #{@class_object.path} { #{body} };"
    else
      "#{indentation}namespace #{namespace.path} { class #{name} { #{body} }; }"
    end
  end

  def add_observer_declarations(observer_path)
    decls = []
    decls << "template<typename T> requires std::derived_from<T, #{observer_path}> bool add_observer(std::shared_ptr<T>& observer)"
    decls << "template<typename T> requires std::derived_from<T, #{observer_path}> bool remove_observer(std::shared_ptr<T>& observer)"
    decls.join('; ') + ';'
  end

end
