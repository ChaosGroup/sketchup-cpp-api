/**
 *  @file   string_literal.hpp
 *  @brief  Single header containing structure that allows to use string as
 *template parameters
 *  @author Alex Tsvetanov
 *  @date   2023-06-04
 ***********************************************/

#pragma once

#include <algorithm>
#include <string_view>

namespace cpp_utils
{
	namespace details
	{
		template <size_t N> struct string_literal
		{
			constexpr static size_t size = N;

			inline constexpr string_literal(const char (&str)[N])
			{
				std::copy_n(str, N, value);
			}

			inline constexpr operator std::string_view() const
			{
				return std::string_view(value);
			}

			inline constexpr std::string_view to_sv() const
			{
				return std::string_view(value);
			}

			char value[N];
		};
	} // namespace details

	namespace literals
	{
		template <cpp_utils::details::string_literal Str> inline constexpr decltype(Str) operator""_sl()
		{
			return Str;
		}
	} // namespace literals
} // namespace cpp_utils
