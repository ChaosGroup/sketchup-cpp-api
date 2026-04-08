#pragma once

#include <string>

static std::string description_to_function_name(std::string description)
{
	// test_... so testup can detect it as a test
	description = "test__should_" + description;
	for (auto& x : description)
		if (x == ' ') x = '_';
		else if (x == ':') x = '_';
		else if (x == '(') x = '_';
		else if (x == ')') x = '_';
		else if (x == '\'') x = '_';
		else if (x == '+') x = '_';
	return description;
}

struct RB_TEST_MODULE
{
private:
	VALUE rb_module = Qnil;
public:
	RB_TEST_MODULE tests(const char* module_name)
	{
		RB_TEST_MODULE nested;
		if (rb_module == Qnil)
			nested.rb_module = rb_define_module(module_name);
		else
			nested.rb_module = rb_define_module_under(rb_module, module_name);
		return nested;
	}
	RB_TEST_MODULE& setup(VALUE(&f)(VALUE))
	{
		rb_define_method(rb_module, "setup", RUBY_METHOD_FUNC(f), 0);
		return *this;
	}
	RB_TEST_MODULE& should(std::string description, VALUE(&f)(VALUE))
	{
		rb_define_method(rb_module, description_to_function_name(description).c_str(), RUBY_METHOD_FUNC(f), 0);
		return *this;
	}
} TestSuit;

template<typename T, typename Y>
void must_be_equal(VALUE self, T res, Y expected, const char* message)
{
	RubyUtils::Object(self).send("assert", expected == res, rb_str_buf_new_cstr(message));
}

template<typename T, typename Y>
void must_be_equal(VALUE self, T res, Y expected, std::string message)
{
	RubyUtils::Object(self).send("assert", expected == res, rb_str_buf_new_cstr(message.c_str()));
}
