namespace RubyUtils
{
	/**
	 * @brief Get the fundamental Ruby type equivalent of the C++ type T
	 *
	 * @tparam T C++ type
	 * @return ruby_value_type Returns the fundamental Ruby type equivalent of the C++ type T
	 */
	template <concepts::is_ruby_constructable T> inline static constexpr ruby_value_type get_fundamental_type()
	{
		using cleaned_T = std::remove_cvref_t<T>;
		// Numeric
		if constexpr (
			std::is_same_v<short, cleaned_T> || std::is_same_v<unsigned short, cleaned_T> || std::is_same_v<int, cleaned_T> || std::is_same_v<unsigned int, cleaned_T> ||
			std::is_same_v<long, cleaned_T> || std::is_same_v<unsigned long, cleaned_T> || std::is_same_v<long long, cleaned_T>)
		{
			return ruby_value_type::RUBY_T_BIGNUM;
		}
		// floating point
		else if constexpr (std::is_same_v<float, cleaned_T> || std::is_same_v<double, cleaned_T> || std::is_same_v<long double, cleaned_T>)
		{
			return ruby_value_type::RUBY_T_FLOAT;
		}
		// string
		else if constexpr (std::is_same_v<std::string_view, cleaned_T> || std::is_same_v<std::string, cleaned_T> || std::is_same_v<char*, cleaned_T> || std::is_same_v<const char*, cleaned_T>)
		{
			return ruby_value_type::RUBY_T_STRING;
		}
		// boolean
		else if constexpr (std::is_same_v<bool, cleaned_T>)
		{
			return ruby_value_type::RUBY_T_TRUE;
		}
		else
		{
			return ruby_value_type::RUBY_T_OBJECT;
		}
	}
} // namespace RubyUtils
