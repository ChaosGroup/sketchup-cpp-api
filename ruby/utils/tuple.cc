namespace RubyUtils
{
	template <typename... Ts> tuple<Ts...>::tuple() : tuple(Qnil)
	{
	}

	template <typename... Ts> tuple<Ts...>::tuple(VALUE val) : IObject(val)
	{
	}

	template <typename... Ts> tuple<Ts...>::tuple(const IObject& val) : IObject(val)
	{
	}

	template <typename... Ts> tuple<Ts...>::tuple(IObject&& val) : IObject(val)
	{
	}

	template <typename... Ts> tuple<Ts...>::tuple(Ts... args) : IObject(rb_ary_new_capa(sizeof...(Ts)))
	{
		(rb_ary_push(this->to_ruby(), IObject::cpp_to_ruby(args)), ...);
	}

	template <std::size_t I, typename... Types> typename std::tuple_element<I, std::tuple<Types...>>::type get(const tuple<Types...>& t) noexcept
	{
		return typename std::tuple<Types...>::template ruby_to_cpp<typename std::tuple_element<I, std::tuple<Types...>>::type>(RARRAY_AREF(t.to_ruby(), I));
	}
} // namespace RubyUtils
