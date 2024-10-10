# SketchUp C++ API

This is a c++ wrapper around the SketchUp ruby api.  It provides a way of writing safer code thanks to compile time checks and the use of std::optional for handling methods that return nil.

Example:
```
using namespace HostApp;
std::optional<Sketchup::Model> active_model = Sketchup().active_model();
if (!active_model.has_value()) {
    printf("No active model\n");
}
Sketchup::Model& model = active_model.value();
model.materials().each([](Sketchup::Material material) {
    printf("%s\n", material.name().c_str());
});
```
