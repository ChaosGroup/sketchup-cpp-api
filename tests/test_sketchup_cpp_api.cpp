#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest.h>
#include <hostapp.hpp>

TEST_CASE("test_sketchup_cpp_api returns true") {
    CHECK(false);
}

extern "C"
void Init_test_sketchup_cpp_api()
{
    doctest::Context ctx;
    ctx.run();
}
