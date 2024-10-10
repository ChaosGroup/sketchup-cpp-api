#pragma once

#include <ruby.h>
#include <string>
#include <type_traits>
#include <vector>
#include <functional>
#include <stdarg.h>
#include <memory>
#include <stdexcept>

#include "./fundamental_types.hpp"

namespace RubyUtils
{
	namespace details
	{
		class INamedRubyWrapper { };

		/**
		 * @brief Interface for C++ Wrapper for Ruby's Object class
		 * 
		 */
		template<cpp_utils::details::string_literal class_name>
		class NamedRubyWrapper : public INamedRubyWrapper
		{
			public:
			static constexpr std::string_view get_klass_name() { return class_name.to_sv(); }
		};

		/**
		 * @brief Ruby object wrapper
		 *
		 */
		class IObject
		{
			protected:
			VALUE value;

			/**
			 * @internal
			 * @brief Cast Ruby object to C++ type
			 *
			 * @tparam T Result type
			 * @param val Ruby object
			 * @return T C++ object from the Ruby object
			 */
			template <typename T> static inline T ruby_to_cpp(VALUE val);

			public:
			/**
			 * @brief Construct a new IObject object from a Ruby object
			 *
			 * @param obj Ruby object
			 */
			inline IObject(VALUE obj);

			/**
			 * @brief Construct a new IObject object from Ruby code
			 *
			 * @param expression Ruby code
			 */
			inline IObject(std::string_view expression);

			/**
			 * @brief Gets the raw Ruby object
			 *
			 * @return VALUE Reference to raw Ruby object
			 */
			inline VALUE to_ruby() const;

			/**
			 * @brief Check if the wrapped Ruby object is nil
			 *
			 * @return bool true if the object is nil, false otherwise
			 */
			inline bool is_nil();

			protected:
			/**
			 * @brief Wrapper for https://apidock.com/ruby/Object/send
			 *
			 * @tparam T Return type. The Ruby result will be cast to this type
			 * @tparam Args Types of the parameters of the methods. Must be convertible to VALUE
			 * @param func Name of the Ruby methods that is being called.
			 * @param args Parameters for the Ruby methods
			 * @return T Ruby result converted to this type
			 */
			template <typename T = IObject, typename... Args> inline T _send(std::string_view func, Args... args) const;

			/**
			 * @brief Wrapper for https://apidock.com/ruby/Object/send by rescuing all the Ruby errors
			 *
			 * @tparam T Return type. The Ruby result will be cast to this type
			 * @tparam Args Types of the parameters of the methods. Must be convertible to VALUE
			 * @param func Name of the Ruby methods that is being called.
			 * @param args Parameters for the Ruby methods
			 * @return T Ruby result converted to this type
			 */
			template <typename T, typename... Args> inline RubyUtils::optional<T> _rescued_send(std::string_view func, Args... args) const;

			/**
			 * @brief Converts native C++ value or object into Ruby object
			 *
			 * @tparam RubyType Fundamental Ruby type value equivalent to T
			 * @tparam T C++ type of the value or object
			 * @param val C++ value or object
			 * @return Object Return Tuby object
			 */
			template<RubyUtils::concepts::is_ruby_constructable T> static inline VALUE cpp_to_ruby(T val)
			{
				using cleaned_T = std::remove_cvref_t<T>;
				static constexpr ruby_value_type RubyType = RubyUtils::get_fundamental_type<cleaned_T>();
				if constexpr (RubyType == ruby_value_type::RUBY_T_TRUE)
				{
					return val ? Qtrue : Qfalse;
				}
				else if constexpr (RubyType == ruby_value_type::RUBY_T_OBJECT)
				{
					if constexpr (std::is_same_v<cleaned_T, VALUE>)
					{
						return val;
					}
					else if constexpr (!std::is_same_v<cleaned_T, VALUE>)
					{
						return val.to_ruby();
					}
				}
				else if constexpr (RubyType == ruby_value_type::RUBY_T_BIGNUM)
				{
					if constexpr (std::is_signed_v<cleaned_T>)
					{
						return RB_LONG2NUM(val);
					}
					else
					{
						return RB_ULONG2NUM(val);
					}
				}
				else if constexpr (RubyType == ruby_value_type::RUBY_T_FLOAT)
				{
					return rb_float_new(val);
				}
				else if constexpr (RubyType == ruby_value_type::RUBY_T_STRING)
				{
					if constexpr (std::is_same_v<std::string, cleaned_T>)
					{
						return rb_utf8_str_new_cstr(val.c_str());
					}
					else if constexpr (std::is_same_v<std::string_view, cleaned_T>)
					{
						return rb_utf8_str_new_cstr(val.data());
					}
					else if constexpr (!std::is_same_v<std::string, cleaned_T> && !std::is_same_v<std::string_view, cleaned_T>)
					{
						return rb_utf8_str_new_cstr(val);
					}
				}
			}

			protected:
			/**
			 * @brief Construct a new IObject object using Ruby constructor
			 *
			 * @tparam T Ruby object types or wrapped Ruby object types
			 * @param klass Name of the Ruby class
			 * @param args Arguments for the constructor
			 */
			template <typename... T> inline IObject(std::string klass, T... args);

			/**
			 * @brief Construct a new IObject object using Ruby constructor
			 *
			 * @tparam T Ruby object types or wrapped Ruby object types
			 * @param klass Ruby pointer to class
			 * @param args Arguments for the constructor of the class
			 */
			template <typename... T> inline IObject(VALUE klass, T... args);

			/**
			 * @brief Creates Ruby array object from iterable C++ object / https://apidock.com/ruby/Object/to_a
			 *
			 * @tparam T Iterable type. Has std::begin and std::end specified.
			 * @return Object The resultant Ruby object
			 */
			template <typename T> inline static IObject array_to_ruby(T list)
			{
				const size_t size = std::distance(std::begin(list), std::end(list));
				std::vector<VALUE> elements(size);
				auto it = std::begin(list);
				for (size_t i = 0; i < size; i++, it++)
				{
					elements[i] = (cpp_to_ruby(*it));
				}
				return IObject(rb_ary_new4(static_cast<long>(size), elements.data()));
			}

			/**
			 * @brief Creates Ruby array object from iterable C++ object with given size / https://apidock.com/ruby/Object/to_a
			 *
			 * @tparam T Pointer or iterator type to the beginning of the iterable.
			 * @return Object The resultant Ruby object
			 */
			template <typename T> inline static IObject array_to_ruby(T list_start, const size_t size)
			{
				std::vector<VALUE> elements(size);
				auto it = list_start;
				for (size_t i = 0; i < size; i++, it++)
				{
					elements[i] = (cpp_to_ruby(*it));
				}
				return IObject(rb_ary_new4(static_cast<long>(size), elements.data()));
			}

			/**
			 * @brief Creates Ruby hash object from 2D iterable C++ object / https://apidock.com/ruby/v2_5_5/Array/to_h
			 *
			 * @tparam T Iterable type. Has std::begin and std::end specified.
			 * @return Object The resultant Ruby object
			 */
			template <typename T> inline static IObject array_to_ruby_hash(T list)
			{
				static constexpr std::string_view to_h = "to_h";

				const size_t size = std::distance(std::begin(list), std::end(list));
				std::vector<VALUE> elements(size);
				auto it = std::begin(list);
				for (size_t i = 0; i < size; i++, it++)
				{
					elements[i] = array_to_ruby(std::begin(*it), 2).to_ruby();
				}
				IObject result = IObject(rb_ary_new4(static_cast<long>(size), elements.data())).send(to_h.data());
				return result;
			}

			public:
			/**
			 * @brief Wrapper for https://apidock.com/ruby/Object/send
			 *
			 * @tparam Args Types of the parameters of the methods. Must be convertible to VALUE
			 * @param func Name of the Ruby methods that is being called.
			 * @param args Parameters for the Ruby methods
			 * @return VALUE Ruby result converted to this type
			 */
			template <typename... Args> inline VALUE send(std::string_view func, Args... args);

			/**
			 * @brief Wrapper for https://apidock.com/ruby/Object/is_a%3F
			 *
			 * @param cls Ruby object pointing to the Ruby class that is to test the current object with.
			 * @return bool true if the Ruby object is of type cls, false otherwise
			 */
			inline bool is_a(RubyClass cls) const;

			template <typename T> inline std::optional<T> as() const;

			template<typename... Ts>
			friend class RubyUtils::any_of;

			template<typename T>
			friend class RubyUtils::optional;
		};
	}

	class Object : public details::IObject, details::NamedRubyWrapper<"Object"> 
	{
		public:
		/**
		 * @brief Construct a new Object object from a Ruby object
		 *
		 * @param obj Ruby object
		 */
		inline Object(VALUE obj) : IObject(obj) { }

		/**
		 * @brief Construct a new Object object from Ruby code
		 *
		 * @param expression Ruby code
		 */
		inline Object(std::string_view expression) : IObject(expression) { }
	};
} // namespace RubyUtils

#include "object.cc"
