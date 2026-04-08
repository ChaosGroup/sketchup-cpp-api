#include <hostapp.hpp>

static VALUE test_sketchup_cpp_api(VALUE self)
{
    return Qtrue;
}

extern "C"
void Init_test_sketchup_cpp_api()
{
    rb_define_global_function("test_sketchup_cpp_api", test_sketchup_cpp_api, 0);
}
