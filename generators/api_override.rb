# Dynamic fixes for incorrect YARD stubs that don't match runtime behavior.
# Loaded (not YARD-parsed) by api_interface.rb after parsing the stubs.

def fix_return(method_path, types)
  m = YARD::Registry.at(method_path)
  return unless m
  m.docstring.delete_tags(:return)
  m.docstring.add_tag(YARD::Tags::Tag.new(:return, '', types))
end

# Sketchup.active_model can return nil
fix_return 'Sketchup.active_model', ['Sketchup::Model', 'nil']

# Setter methods return nil, not String as the stubs claim
fix_return 'Sketchup.status_text=', ['nil']
fix_return 'Sketchup.vcb_label=',   ['nil']
fix_return 'Sketchup.vcb_value=',   ['nil']

# template= returns Boolean, not String
fix_return 'Sketchup.template=',    ['Boolean']
