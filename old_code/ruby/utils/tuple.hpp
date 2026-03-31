#pragma once

#include "object.hpp"
#include <tuple>

namespace RubyUtils
{
	template <typename... Ts> class tuple final : public details::IObject
	{
		public:
		inline tuple();
		inline tuple(VALUE val);
		inline tuple(const IObject& val);
		inline tuple(IObject&& val);
		inline tuple(Ts... args);

		template <std::size_t I, typename... Types> friend inline typename std::tuple_element<I, std::tuple<Types...>>::type get(const tuple<Types...>&) noexcept;
	};

	template <std::size_t I, typename... Types> inline typename std::tuple_element<I, std::tuple<Types...>>::type get(const tuple<Types...>& t) noexcept;
} // namespace RubyUtils

#include "tuple.cc"
