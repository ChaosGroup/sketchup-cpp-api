#include <hostapp/sketchup.hpp>
#include <sstream>
#include "GenericSetup.hpp"

using namespace HostApp;

static VALUE test1(VALUE self)
{
	Sketchup::Material material = RubyUtils::Object("@material");
	auto cpp_api_name = material.name();
	VALUE ruby_obj = rb_eval_string("@material.name");
	std::string ruby_name = rb_string_value_cstr(&ruby_obj);
	std::stringstream ss;
	ss << "@material is incorrectly named " << cpp_api_name << " instead of " << ruby_name << ".";
	must_be_equal(self, cpp_api_name, ruby_name, ss.str());
	return self;
}

static VALUE setup (VALUE) {
	return rb_eval_string(R"(
		@material = Sketchup.active_model.materials.first
	)");
}

extern "C"

#ifdef _WIN32
__declspec(dllexport)
#endif

void Init_TestMaterial(void)
{
	TestSuit
	.tests("Sketchup_Tests")
		.tests("Material")
			.setup(setup)
			.should("::name() should return the material\'s name", test1);
}
