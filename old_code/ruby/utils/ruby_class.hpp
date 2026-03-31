#pragma once

#include "object.hpp"

namespace RubyUtils
{
	class RubyClass : public details::IObject
	{
		public:
		inline RubyClass(VALUE x);
		inline RubyClass(std::string_view expression);
	};
} // namespace RubyUtils

#include "ruby_class.cc"
