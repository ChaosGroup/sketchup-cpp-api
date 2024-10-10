#pragma once

#include <ruby.h>
#include <string>
#include <type_traits>
#include <vector>
#include <variant>
#include <functional>
#include <stdarg.h>
#include <memory>
#include <stdexcept>
#include <variant>

#include "./object.hpp"

namespace RubyUtils
{
	namespace details
	{
		template <typename T> constexpr inline bool is_named_ruby_t()
		{
			return std::is_base_of_v<details::INamedRubyWrapper, T>;
		}

		template <typename T, typename U = typename std::conditional<is_named_ruby_t<T>(), T, void>::type> class get_klass;

		template <typename T> class get_klass<T, T>
		{
			public:
			static constexpr std::string_view klass = T::get_klass_name();
		};

		template <typename T> class get_klass<T, void>
		{
			public:
			static constexpr std::string_view klass = "Not Ruby type";
		};

		template <typename T> class RubyWrapper
		{
			T* value;

			public:
			using wrapped_type = T;
			static constexpr std::string_view klass = get_klass<T>::klass;
			inline RubyWrapper() : value(nullptr)
			{
			}

			inline RubyWrapper(const T& val)
			{
				value = new T(val);
			}

			inline RubyWrapper(VALUE val)
			{
				if constexpr (is_ruby_t<T>())
				{
					value = new T(val);
				}
				if constexpr (!is_ruby_t<T>())
				{
					value = new T(RubyUtils::details::IObject::ruby_to_cpp<T>(val));
				}
			}

			inline T* to_ptr()
			{
				return value;
			}

			inline operator T&()
			{
				return *value;
			}
		};

		template <typename T1, typename... Ts> struct FirstConvertibleFrom;

		template <typename T1, typename T2, typename... Ts> struct FirstConvertibleFrom<T1, T2, Ts...>
		{
			using type = typename std::conditional<std::is_convertible_v<T1, T2>, T2, typename FirstConvertibleFrom<T1, Ts...>::type>::type;
		};

		template <typename T1> struct FirstConvertibleFrom<T1>
		{
			using type = void;
		};

	} // namespace

	template <typename... Ts> class any_of : public ISpecialStdWrapper
	{
		std::variant<details::RubyWrapper<Ts>...> obj;

		public:
		inline any_of() = default;

		template <typename T1> inline any_of(const T1& val)
		{
			static constexpr bool not_have_to_default_convert = ((std::is_same_v<T1, Ts>) || ...) || std::is_same_v<T1, VALUE> || std::is_same_v<T1, Object>;

			static_assert(not_have_to_default_convert || std::is_same_v<typename details::FirstConvertibleFrom<T1, Ts...>::type, void>, "no suitable conversion");

			if constexpr (((std::is_same_v<T1, Ts>) || ...))
			{
				obj = details::RubyWrapper<T1>(val);
			}

			else if constexpr (std::is_same_v<T1, VALUE>)
			{
				if (val != Qnil)
				{
					VALUE ruby_klass = rb_funcall(rb_funcall(val, rb_intern("class"), 0), rb_intern("to_s"), 0);
					const std::string_view klass = rb_string_value_cstr(&ruby_klass);
					if (!this->try_setting_value(val, klass))
					{
						rb_raise(rb_eRuntimeError, "The given Ruby object, cannot fit in this any_of object");
					}
				}
			}

			else if constexpr (std::is_same_v<T1, Object>)
			{
				if (val != Qnil)
				{
					VALUE ruby_klass = rb_funcall(rb_funcall(val.to_ruby(), rb_intern("class"), 0), rb_intern("to_s"), 0);
					const std::string_view klass = rb_string_value_cstr(&ruby_klass);
					if (!this->try_setting_value(val.to_ruby(), klass))
					{
						rb_raise(rb_eRuntimeError, "The given Ruby object, cannot fit in this any_of object");
					}
				}
			}

			else if constexpr (!not_have_to_default_convert)
			{
				using match_type = typename details::FirstConvertibleFrom<T1, Ts...>::type;
				obj = details::RubyWrapper<match_type>(match_type(val));
			}
		}

		template <class T> inline constexpr T& get()
		{
			return std::get<details::RubyWrapper<T>>(obj);
		}

		template <class T> inline constexpr T* get_if() noexcept
		{
			if (auto* ptr = std::get_if<details::RubyWrapper<T>>(&obj))
			{
				return ptr->to_ptr();
			}
			return nullptr;
		}

		template <typename T> inline constexpr bool holds_alternative() noexcept
		{
			return std::holds_alternative<details::RubyWrapper<T>>(obj);
		}

		inline VALUE to_ruby()
		{
			return Qnil;
		}

		private:
		template <typename T_lookup, typename T_construct, typename T> inline constexpr bool set(T x)
		{
			if constexpr ((std::is_same_v<T_lookup, Ts> || ...))
			{
				obj = details::RubyWrapper<T_lookup>(T_construct(x));
				return true;
			}
			if constexpr (!(std::is_same_v<T_lookup, Ts> || ...))
			{
				return false;
			}
			return false;
		}

		inline bool try_setting_value(VALUE ruby_obj, const std::string_view klass)
		{
			bool success = false;
			(((details::RubyWrapper<Ts>::klass == klass) ? (success = success || this->template set<Ts, Ts>(RubyUtils::Object::ruby_to_cpp<Ts>(ruby_obj)), 0) : (0)),
			 ...);
			return success;
		}
	};

} // namespace RubyUtils
