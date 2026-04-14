# SketchUp C++ API

A C++20 header-only wrapper around the SketchUp Ruby C API. Write SketchUp extensions in C++ with compile-time type safety, `std::optional` for nil-returning methods, and `std::variant` for methods that return multiple types.

Targets SketchUp 2021-2026 (Ruby 2.7 for 2021-2023, Ruby 3.2 for 2024+). Supported platforms: Windows (MSVC) and macOS.

## Usage

### 1. Install

```sh
cmake -Bbuild
cmake --install build --prefix /path/to/install
```

### 2. Add to your CMake project

```cmake
cmake_minimum_required(VERSION 3.30)
project(MyExtension)

find_package(SketchUpCppAPI REQUIRED)

add_library(my_extension MODULE my_extension.cpp)
target_link_libraries(my_extension SketchUpCppAPI::2026)

set_target_properties(my_extension PROPERTIES PREFIX "")
if(WIN32)
    set_target_properties(my_extension PROPERTIES SUFFIX .so)
elseif(APPLE)
    set_target_properties(my_extension PROPERTIES SUFFIX .bundle)
endif()
```

The `SketchUpCppAPI::2026` target provides include paths, Ruby link libraries, compile definitions, and the C++20 requirement. Replace `2026` with the SketchUp version you're targeting (2021-2026).

### 3. Write your extension

```cpp
#include <SketchUpCppAPI/SketchUpCppAPI.hpp>

using namespace SketchUpCppAPI::HostApp;

extern "C" void Init_my_extension()
{
    auto model = Sketchup::active_model();
    if (model)
        UI::messagebox(Sketchup::app_name() + " " + Sketchup::version(), 0L);
}
```

### 4. Load in SketchUp

Create a Ruby loader script:

```ruby
require File.join(__dir__, 'my_extension')
```

Then launch SketchUp with it:

```
SketchUp -RubyStartup path/to/loader.rb
```

## Observers

Observers use C++ virtual classes. Inherit from the observer base, override callbacks as `public`, and pass a `shared_ptr` to `add_observer`. Only overridden methods are registered on the Ruby object -- SketchUp never calls the rest.

```cpp
#include <SketchUpCppAPI/SketchUpCppAPI.hpp>
#include <iostream>

using namespace SketchUpCppAPI::HostApp;

static std::shared_ptr<struct MyObserver> g_observer;

struct MyObserver : Sketchup::ModelObserver
{
public:
    void onDeleteModel(Sketchup::Model model) override
    {
        std::cout << "Model deleted!" << std::endl;
    }
};

extern "C" void Init_my_observer()
{
    g_observer = std::make_shared<MyObserver>();
    auto model = Sketchup::active_model();
    if (model)
        model->add_observer(g_observer);
}
```

The Ruby object wraps a `std::shared_ptr`, so the C++ observer survives Ruby GC.

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

---

## Contributing

### Building from source

Requires CMake 3.30+ and recursive submodule init:

```sh
git submodule update --init --recursive
cmake -Bbuild
cmake --build build
```

### Project structure

```
include/SketchUpCppAPI/
  SketchUpCppAPI.hpp    Entry point (includes the below)
  _Types.hpp            Object, to_ruby/from_ruby, protect()
  _Observers.hpp        Observer core infrastructure

generators/                Code generation from YARD stubs
  ruby-api-stubs/          SketchUp Ruby API stubs (submodule)
  generate.rb              Entry point (run by CMake at configure time)
  class_interface.rb       Class and observer class generation
  method_interface.rb      Method generation with type mapping
  observer_interface.rb    Observer concepts, trampolines, registration
  module_interface.rb      Module generation

examples/
  hello_sketchup.cpp       Shows a messagebox with version info
  app_observer.cpp         Registers an AppObserver, prints on new model

tests/
  test_sketchup_module.cpp API tests (run inside SketchUp via doctest)
```

### Code generation

Class stubs and module methods are generated from the [SketchUp Ruby API YARD stubs](https://github.com/nicholasnelson/sketchup-api-stubs). Observer classes get special treatment: protected virtual methods, per-method concepts for override detection, and typed `add_observer` template overloads.

The generator runs automatically during `cmake -Bbuild`. To regenerate after modifying stubs or generator scripts, re-run `cmake -Bbuild`.

### Running tests

Tests are C++ MODULE libraries loaded by Ruby inside SketchUp:

```
SketchUp -RubyStartup '<build>/tests/<config>/run_test_sketchup_cpp_api.rb'
```

In Xcode or Visual Studio, select the `test_sketchup_cpp_api` target and press Run -- the debugger launch is preconfigured.
