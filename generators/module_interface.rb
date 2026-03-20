class ModuleInterface

  def initialize(module_object)
    @module_object = module_object
  end

  def forward_declare
    "namespace #{@module_object.path} {}"
  end

end
