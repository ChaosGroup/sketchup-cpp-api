namespace RubyUtils
{
	/**
	 * @brief Executes Ruby code from string
	 *
	 * @return VALUE Ruby object of the result of the Ruby code
	 */
	inline VALUE exec(std::string_view expr)
	{
		return rb_eval_string(expr.data());
	}
} // namespace RubyUtils
