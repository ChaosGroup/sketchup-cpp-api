#pragma once

#include "../../cpp/utils/string_literal.hpp"
#include <concepts>

namespace RubyUtils
{
	template <cpp_utils::details::string_literal _key, typename _value> struct Key
	{
		using value_t = _value;
		static inline constexpr std::string_view key()
		{
			return _key.to_sv();
		}
	};

	template <concepts::Key... Ts> class Hash : public RubyUtils::details::IObject
	{
		private:
		static constexpr auto indexes = std::make_index_sequence<sizeof...(Ts)>{};

		template <typename V> inline void insert_if_allowed(std::string_view key, V val) noexcept
		{
			if (((Ts::key() == key) || ...))
			{
				rb_hash_aset(value, rb_intern_const(key.data()), RubyUtils::details::IObject::cpp_to_ruby(val));
			}
		}

		template <concepts::Key key> inline void copy_if_exists(VALUE from) noexcept
		{
			ID ruby_key = rb_intern_const(key::key().data());
			VALUE val = rb_hash_aref(from, ID2SYM(ruby_key));
			if (val != Qnil)
			{
				rb_hash_aset(value, ruby_key, val);
			}
		}

		template <cpp_utils::details::string_literal key, size_t... inds>
			requires(((key.to_sv() == Ts::key()) || ...) && sizeof...(inds) == sizeof...(Ts))
		struct key_type
		{
			static constexpr size_t index = ((inds * (key.to_sv() == Ts::key())) + ...);
			using type = typename std::tuple_element<index, std::tuple<typename Ts::value_t...>>::type;
		};

		public:
		template <typename... Vs> inline Hash(std::pair<std::string_view, Vs>... args) noexcept : IObject(rb_hash_new())
		{
			(this->insert_if_allowed(args.first, args.second), ...);
		}

		inline Hash(VALUE val) : IObject(rb_hash_new())
		{
			(copy_if_exists<Ts>(val), ...);
		}

		template <typename... Us> inline Hash(Hash<Us...> val) : IObject(rb_hash_new())
		{
			(copy_if_exists<Ts>(val.to_ruby()), ...);
		}

		private:
		template <cpp_utils::details::string_literal key, size_t... inds>
			requires(((key.to_sv() == Ts::key()) || ...) && sizeof...(Ts) == sizeof...(inds))
		inline std::optional<typename key_type<key, inds...>::type> _get(std::index_sequence<inds...>)
		{
			static ID ruby_key = rb_intern_const(key.to_sv().data());
			VALUE val = rb_hash_aref(value, ruby_key);
			if (val == Qnil)
			{
				return std::nullopt;
			}
			return RubyUtils::details::IObject::ruby_to_cpp<typename key_type<key, inds...>::type>(val);
		}

		template <cpp_utils::details::string_literal key, size_t... inds>
			requires(((key.to_sv() == Ts::key()) || ...))
		inline Hash<Ts...>& _set(typename key_type<key, inds...>::type new_value, std::index_sequence<inds...>)
		{
			rb_hash_aset(value, rb_intern_const(key.to_sv().data()), IObject::cpp_to_ruby(new_value));
			return *this;
		}

		public:
		template <cpp_utils::details::string_literal key>
			requires(((key.to_sv() == Ts::key()) || ...))
		inline auto get()
		{
			return _get<key>(std::make_index_sequence<sizeof...(Ts)>{});
		}

		template <cpp_utils::details::string_literal key, typename T>
			requires(((key.to_sv() == Ts::key()) || ...))
		inline Hash<Ts...>& set(T new_value)
		{
			return _set<key>(new_value, std::make_index_sequence<sizeof...(Ts)>{});
		}
	};

} // namespace RubyUtils
