#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest.h>

extern "C"
void Init_test_sketchup_cpp_api()
{
    doctest::Context ctx;
    ctx.run();
}
