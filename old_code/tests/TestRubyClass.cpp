#include <hostapp/sketchup.hpp>
#include <sstream>
#include "GenericSetup.hpp"

using namespace HostApp;

static VALUE test1(VALUE self)
{
	VALUE cpp_gathered_klass = RubyUtils::get_class<Sketchup::Material>().to_ruby();
	VALUE ruby_gathered_klass = rb_eval_string("Sketchup::Material");
	must_be_equal(self, cpp_gathered_klass, ruby_gathered_klass, "C++ API and rb_eval_string retrieved different Ruby objects.");
	return self;
}

static VALUE test2(VALUE self)
{
	VALUE cpp_gathered_klass = RubyUtils::get_class<Sketchup::Materials>().to_ruby();
	VALUE ruby_gathered_klass = rb_eval_string("Sketchup::Materials");
	must_be_equal(self, cpp_gathered_klass, ruby_gathered_klass, "C++ API and rb_eval_string retrieved different Ruby objects.");
	return self;
}

static VALUE test3(VALUE self)
{
	VALUE cpp_gathered_klass = RubyUtils::get_class<Sketchup::Model>().to_ruby();
	VALUE ruby_gathered_klass = rb_eval_string("Sketchup::Model");
	must_be_equal(self, cpp_gathered_klass, ruby_gathered_klass, "C++ API and rb_eval_string retrieved different Ruby objects.");
	return self;
}

extern "C"

#ifdef _WIN32
__declspec(dllexport)
#endif

void Init_TestRubyClass(void)
{
	TestSuit
	.tests("RubyUtils_Tests")
		.tests("RubyClass")
			.tests("Get_class")
				.should("return Ruby's Sketchup::Material when C++ class Sketchup::Material is passed as template parameter", test1)
				.should("return Ruby's Sketchup::Materials when C++ class Sketchup::Materials is passed as template parameter", test2)
				.should("return Ruby's Sketchup::Model when C++ class Sketchup::Model is passed as template parameter", test3);
}
