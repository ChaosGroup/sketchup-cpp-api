# SketchUp C++ API

A C++20 header-only wrapper around the SketchUp Ruby C API. It provides compile-time type safety and uses `std::optional` / `std::variant` to represent Ruby methods that can return `nil` or multiple types.

Targets SketchUp 2021-2026 (Ruby 2.7 for 2021-2023, Ruby 3.2 for 2024+). Supported platforms: Windows (MSVC) and macOS.

## Quick example

```cpp
#include <SketchUpCppAPI/SketchUpCppAPI.hpp>

using namespace SketchUpCppAPI::HostApp;

extern "C" void Init_my_extension()
{
    auto version = Sketchup::version();
    auto app = Sketchup::app_name();
    UI::messagebox(app + " " + version, 0L);
}
```

## Observers

Observers use C++ virtual classes. Inherit from the observer base, override the callbacks you care about as `public`, and pass a `shared_ptr` to `add_observer`. Only overridden methods are registered on the Ruby object — SketchUp never calls the rest.

```cpp
struct MyModelObserver : Sketchup::ModelObserver
{
public:
    void onDeleteModel(Sketchup::Model model) override
    {
        std::cout << "Model deleted!" << std::endl;
    }
};

auto observer = std::make_shared<MyModelObserver>();
auto model = Sketchup::active_model();
if (model)
    model->add_observer(observer);
```

The Ruby object wraps a `std::shared_ptr`, so the C++ observer survives Ruby GC.

## Building

```sh
# Configure (default: SketchUp 2026 / Ruby 3.2)
cmake -Bbuild

# Other versions
cmake -Bbuild -DSKETCHUP_VERSION=2023

# Build
cmake --build build
```

On macOS, the Xcode generator is used by default. Example and test targets include Xcode scheme configuration for launching SketchUp with the debugger attached.

## Running

SketchUp C extensions are MODULE libraries loaded by Ruby at runtime. After building, launch SketchUp with:

```
SketchUp -RubyStartup '<build>/examples/<config>/run_hello_sketchup.rb'
```

In Xcode or Visual Studio, select an example target and press Run — the debugger launch is preconfigured.

## Project structure

```
include/SketchUpCppAPI/
  SketchUpCppAPI.hpp    Entry point (just includes the below)
  _Types.hpp            Object, to_ruby/from_ruby, protect()
  _Observers.hpp        Observer core infrastructure

generators/                YARD-based code generation
  ruby-api-stubs/          SketchUp Ruby API stubs (submodule)
  generate.rb              Generator entry point
  api_interface.rb         Orchestrates output
  class_interface.rb       Class/observer class generation
  method_interface.rb      Method generation with type mapping
  observer_interface.rb    Observer concepts, trampolines, registration
  module_interface.rb      Module generation

build/.../
  _HostApp.hpp             Generated: all classes, observers, modules

examples/
  hello_sketchup.cpp       Shows a messagebox with version info
  app_observer.cpp         Registers an AppObserver, prints on new model

tests/
  test_sketchup_module.cpp API tests (run inside SketchUp via doctest)
```

## Code generation

Class stubs and module methods are generated from the [SketchUp Ruby API YARD stubs](https://github.com/nicholasnelson/sketchup-api-stubs). Observer classes get special treatment: protected virtual methods, per-method concepts for override detection, and typed `add_observer` template overloads.

To regenerate after modifying the stubs or generator:

```sh
cmake -Bbuild   # runs the generator during configure
```

## Type mapping

| Ruby | C++ |
|------|-----|
| `Integer` | `long` |
| `Float`, `Numeric` | `double` |
| `String` | `std::string` |
| `Symbol` | `const char*` |
| `Boolean` | `bool` |
| `T`, `nil` | `std::optional<T>` |
| `T1`, `T2` | `std::variant<T1, T2>` |
| `Array<T>` | `std::vector<T>` |
| `Array(T1, T2)` | `std::pair<T1, T2>` |
| SketchUp class | HostApp wrapper (holds `VALUE self`) |
