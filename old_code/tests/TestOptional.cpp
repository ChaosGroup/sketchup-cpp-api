#include <hostapp/sketchup.hpp>
#include <sstream>
#include "GenericSetup.hpp"

using namespace HostApp;

static VALUE test1(VALUE self)
{
	RubyUtils::optional<RubyUtils::Object> empty;

	must_be_equal(self, empty.has_value(), false, "Empty optional object incorrectly contains value.");
	must_be_equal(self, empty, std::nullopt, "Empty optional object incorrectly contains value.");

	try
	{
		empty.value();
		must_be_equal(self, true, false, "Empty optional object incorrectly contains value.");
	}
	catch(std::bad_optional_access&)
	{
		// all good
	}
	catch(...)
	{
		must_be_equal(self, true, false, "Empty optional object throw invalid exception when asked for its value.");
	}
	return self;
}

extern "C"

#ifdef _WIN32
__declspec(dllexport)
#endif

void Init_TestOptional(void)
{
	TestSuit
	.tests("RubyUtils_Tests")
		.tests("Optional")
			.should("create nullopt object by default", test1);
}
