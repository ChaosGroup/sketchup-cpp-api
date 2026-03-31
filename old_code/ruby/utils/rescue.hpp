#pragma once

#include <ruby.h>

namespace RubyUtils
{

	namespace
	{
		inline VALUE ruby_rescue_func(const VALUE*)
		{
			return Qnil;
		}

		inline VALUE ruby_call_func(VALUE arg)
		{
			std::function<VALUE()>& f = *reinterpret_cast<std::function<VALUE()>*>(arg);
			return f();
		}
	}

	inline VALUE ruby_rescue(std::function<VALUE()> f)
	{
		return rb_rescue(RUBY_METHOD_FUNC(ruby_call_func), reinterpret_cast<VALUE>(&f), RUBY_METHOD_FUNC(ruby_rescue_func), (VALUE)0);
	}

}
