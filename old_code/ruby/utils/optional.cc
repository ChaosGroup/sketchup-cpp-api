namespace RubyUtils
{
	template<typename T> inline optional<T>::optional(std::nullopt_t) : std::optional<T>(std::nullopt)
	{
	}

	template <typename T> inline optional<T>::optional() : optional(Qnil)
	{
	}

	template <typename T> inline optional<T>::optional(VALUE obj) : std::optional<T>(obj != Qnil ? std::make_optional<T>(RubyUtils::details::IObject::ruby_to_cpp<T>(obj)) : std::nullopt)
	{
	}

	template <typename T> inline optional<T>::optional(T obj) : std::optional<T>(obj != Qnil ? std::make_optional<T>(obj) : std::nullopt)
	{
	}

	template <typename T> inline VALUE optional<T>::to_ruby()
	{
		return this->has_value() ? RubyUtils::details::IObject::cpp_to_ruby(this->value()) : Qnil;
	}
} // namespace RubyUtils
