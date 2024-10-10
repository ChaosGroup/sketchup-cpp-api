#pragma once

#include <ruby.h>

namespace RubyUtils
{
	/**
	 * @brief C++ Wrapper for specific std:: classes used in the API
	 *
	 */
	class ISpecialStdWrapper
	{
		virtual inline VALUE to_ruby() = 0;
	};
} // namespace RubyUtils
