#include <hostapp/sketchup.hpp>
#include <sstream>
#include "GenericSetup.hpp"

using namespace HostApp;

template<typename T, cpp_utils::details::string_literal variable, bool expected>
static VALUE test1(VALUE self)
{
	bool res = RubyUtils::Object(variable.to_sv()).is_a(RubyUtils::get_class<T>());
	std::stringstream ss;
	ss << variable.to_sv() << " is incorrectly considered " << T::get_klass_name() << " instance.";
	must_be_equal(self, res, expected, ss.str());
	return self;
}

static VALUE setup (VALUE) {
	return rb_eval_string(R"(
		@material = Sketchup::active_model.materials.first
		@materials = Sketchup::active_model.materials
		@model = Sketchup::active_model
	)");
}

extern "C"

#ifdef _WIN32
__declspec(dllexport)
#endif

void Init_TestObject(void)
{
	auto suit = TestSuit.tests("RubyUtils_Object_Is_a_klass");
	
	suit
	.tests("Material")
		.setup(setup)
		.should("return true when applied over Sketchup::Material object", test1<Sketchup::Material, "@material", true>)
		.should("return false when applied over Sketchup::Materials object", test1<Sketchup::Materials, "@material", false>)
		.should("return false when applied over Sketchup::Model object", test1<Sketchup::Model, "@material", false>);
	
	suit
	.tests("Materials")
		.setup(setup)
		.should("return false when applied over Sketchup::Material object", test1<Sketchup::Material, "@materials", false>)
		.should("return true when applied over Sketchup::Materials object", test1<Sketchup::Materials, "@materials", true>)
		.should("return false when applied over Sketchup::Model object", test1<Sketchup::Model, "@materials", false>);

	suit
	.tests("Model")
		.setup(setup)
		.should("return false when applied over Sketchup::Material object", test1<Sketchup::Material, "@model", false>)
		.should("return false when applied over Sketchup::Materials object", test1<Sketchup::Materials, "@model", false>)
		.should("return true when applied over Sketchup::Model object", test1<Sketchup::Model, "@model", true>);
}
