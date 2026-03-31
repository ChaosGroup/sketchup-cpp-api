namespace RubyUtils
{
	inline RubyClass::RubyClass(VALUE x) : IObject(x)
	{
	}
	inline RubyClass::RubyClass(std::string_view expression) : IObject(expression)
	{
	}

	/**
	 * @brief Get Ruby handle onto the class object (equivalent to Ruby's `T.class`)
	 *
	 * @tparam T C++ Wrapper for the Ruby class
	 * @return VALUE Ruby handle onto the class object
	 */
	template <typename T> inline RubyClass get_class()
	{
		return rb_eval_string(T::get_klass_name().data());
	}

	inline bool details::IObject::is_a(RubyClass cls) const
	{
		return _send<bool>("is_a?", cls);
	}
} // namespace RubyUtils
