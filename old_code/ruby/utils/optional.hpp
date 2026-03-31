#pragma once

#include "special_std_wrapper.hpp"
#include <optional>
#include <concepts>

namespace RubyUtils
{	
	template <typename T>
	class optional final : public ISpecialStdWrapper, public std::optional<T>
	{
		public:
		using type = T;
		inline optional();
		inline optional(std::nullopt_t);
		inline optional(VALUE obj);
		inline VALUE to_ruby();
		inline optional(T obj);
	};
} // namespace RubyUtils

#include "optional.cc"
