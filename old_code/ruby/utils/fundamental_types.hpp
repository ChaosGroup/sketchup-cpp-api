#pragma once

#include <ruby.h>
#include <concepts>

namespace RubyUtils
{
	namespace concepts
	{
		template <typename T>
		concept is_ruby_constructable = (
			// Numerical
			std::same_as<short, std::remove_cvref_t<T>> || 
			std::same_as<unsigned short, std::remove_cvref_t<T>> || 
			std::same_as<int, std::remove_cvref_t<T>> || 
			std::same_as<unsigned int, std::remove_cvref_t<T>> ||
			std::same_as<long, std::remove_cvref_t<T>> || 
			std::same_as<unsigned long, std::remove_cvref_t<T>> || 
			std::same_as<long long, std::remove_cvref_t<T>> || 
			// floating point
			std::same_as<float, std::remove_cvref_t<T>> ||
			std::same_as<double, std::remove_cvref_t<T>> || 
			std::same_as<long double, std::remove_cvref_t<T>> || 
			// strings
			std::same_as<std::string_view, std::remove_cvref_t<T>> ||
			std::same_as<std::string, std::remove_cvref_t<T>> || 
			std::same_as<char*, std::remove_cvref_t<T>> || 
			std::same_as<const char*, std::remove_cvref_t<T>> || 
			// boolean type
			std::same_as<bool, std::remove_cvref_t<T>> ||
			// Ruby object
			std::same_as<VALUE, std::remove_cvref_t<T>> || 
			// Ruby wrapper object
			std::derived_from<std::remove_cvref_t<T>, RubyUtils::details::IObject> ||
			std::derived_from<std::remove_cvref_t<T>, RubyUtils::ISpecialStdWrapper>
		);
	} // namespace concepts

	/**
	 * @brief Get the fundamental Ruby type equivalent of the C++ type T
	 *
	 * @tparam T C++ type
	 * @return ruby_value_type Returns the fundamental Ruby type equivalent of the C++ type T
	 */
	template <concepts::is_ruby_constructable T> inline static constexpr ruby_value_type get_fundamental_type();
} // namespace RubyUtils

#include "./fundamental_types.cc"
