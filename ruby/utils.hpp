#pragma once

#include <ruby.h>
#include <string_view>
#include <cpp/utils.hpp>

namespace RubyUtils
{

	namespace concepts
	{
		template<typename T>
		concept Key = requires {
			{ T::key() } -> std::same_as<std::string_view>;
			typename T::value_t;
		};
	}

	namespace details
	{
		/**
		 * @brief Interface for C++ Wrapper for Ruby's Object class
		 * 
		 */
		template<cpp_utils::details::string_literal class_name>
		class NamedRubyWrapper;

		/**
		 * @brief C++ Wrapper for Ruby's Object class's functionalities
		 * 
		 */
		class IObject;
	}

	/**
	 * @brief C++ Wrapper for specific std:: classes used in the API
	 * @details Pure abstract class used to identify specific classes
	 *
	 */
	class ISpecialStdWrapper;

	/**
	 * @brief C++ Wrapper for optional Ruby class (aka `T?`)
	 *
	 * @tparam T C++ Wrapper for optional Ruby class
	 */
	template <typename T> class optional;

	/**
	 * @brief C++ Wrapper for any of multiple Ruby classes (aka `<T1, T2, ..., Tn>`)
	 *
	 * @tparam T C++ Wrapper for any of multiple Ruby class
	 */
	template <typename... Ts> class any_of;

	/**
	 * @brief C++ Wrapper for Ruby Hash
	 *
	 * @tparam T C++ Wrapper for Ruby Hash
	 */
	template <concepts::Key... KVPs> class Hash;

	/**
	 * @brief C++ Wrapper for tuple of multiple types
	 *
	 * @tparam Ts The types of the tuple's components
	 */
	template <typename... Ts> class tuple;

	/**
	 * @brief C++ Wrapper for pair of 2 types
	 *
	 * @tparam T1 type of the first component
	 * @tparam T2 type of the second component
	 */
	template <typename T1, typename T2> using pair = tuple<T1, T2>;

	/**
	 * @brief Get the fundamental Ruby type equivalent of the C++ type T
	 *
	 * @tparam T C++ type
	 * @return ruby_value_type Returns the fundamental Ruby type equivalent of the C++ type T
	 */
	template <typename T> static constexpr ruby_value_type get_fundamental_type();

	/**
	 * @brief C++ Wrapper for Ruby's Object class
	 *
	 */
	class Object;

	/**
	 * @brief C++ Wrapper for Ruby's Class class
	 *
	 */
	class RubyClass;

	/**
	 * @brief Executes Ruby code from string
	 *
	 * @return VALUE Ruby object of the result of the Ruby code
	 */
	inline VALUE exec(std::string_view expr);

	/**
	 * @brief Get Ruby handle onto the class object (equivalent to Ruby's `T.class`)
	 *
	 * @tparam T C++ Wrapper for the Ruby class
	 * @return VALUE Ruby handle onto the class object
	 */
	template <typename T> inline RubyClass get_class();
} // namespace RubyUtils

#include "utils.cc"

#include "utils/rescue.hpp"
#include "utils/object.hpp"
#include "utils/ruby_class.hpp"
#include "utils/special_std_wrapper.hpp"
#include "utils/fundamental_types.hpp"
#include "utils/optional.hpp"
#include "utils/tuple.hpp"
#include "utils/enumerable.hpp"
#include "utils/any_of.hpp"
#include "utils/type_of.hpp"
#include "utils/hash.hpp"
