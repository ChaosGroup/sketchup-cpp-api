namespace RubyUtils::details
{

	/**
	 * @internal
	 * @brief Cast Ruby object to C++ type
	 *
	 * @tparam T Result type
	 * @param val Ruby object
	 * @return T C++ object from the Ruby object
	 */
	template <typename T> inline T IObject::ruby_to_cpp(VALUE val)
	{
		static_assert(
			std::is_base_of_v<IObject, T> || std::is_base_of_v<ISpecialStdWrapper, T> || std::is_same_v<bool, T> || std::is_convertible_v<char*, T> ||
				std::is_same_v<char, T> || std::is_same_v<short, T> || std::is_same_v<unsigned short, T> || std::is_same_v<int, T> ||
				std::is_same_v<unsigned int, T> || std::is_same_v<long, T> || std::is_same_v<unsigned long, T> || std::is_same_v<long long, T> ||
				std::is_same_v<unsigned long long, T> || std::is_same_v<double, T> || std::is_same_v<float, T>,
			"No viable conversion to result type.");
		// Safe conversions:
		// C++ wrapped Ruby object
		if constexpr (std::is_base_of_v<IObject, T>)
		{
			return T(val);
		}
		else if constexpr (std::is_base_of_v<ISpecialStdWrapper, T>)
		{
			return T(val);
		}
		// Not safe conversions:
		// Boolean type
		else if constexpr (std::is_same_v<bool, T>)
		{
			return RTEST(val);
		}
		// string types
		else if constexpr (std::is_convertible_v<char*, T>)
		{
			return T(rb_string_value_cstr(&val));
		}
		// Boolean type
		else if constexpr (std::is_same_v<bool, T>)
		{
			return RTEST(val);
		}
		// Numeric types
		else if constexpr (std::is_same_v<char, T>)
		{
			return NUM2CHR(val);
		}
		else if constexpr (std::is_same_v<short, T>)
		{
			return NUM2SHORT(val);
		}
		else if constexpr (std::is_same_v<unsigned short, T>)
		{
			return NUM2USHORT(val);
		}
		else if constexpr (std::is_same_v<int, T>)
		{
			return NUM2INT(val);
		}
		else if constexpr (std::is_same_v<unsigned int, T>)
		{
			return NUM2UINT(val);
		}
		else if constexpr (std::is_same_v<long, T>)
		{
			return NUM2LONG(val);
		}
		else if constexpr (std::is_same_v<unsigned long, T>)
		{
			return NUM2ULONG(val);
		}
		else if constexpr (std::is_same_v<long long, T>)
		{
			return NUM2LL(val);
		}
		else
		{ // same as: if constexpr (std::is_same_v<double, T> || std::is_same_v<float, T>)
			return static_cast<T>(NUM2DBL(val));
		}
	}

	/**
	 * @brief Construct a new IObject object from a Ruby object
	 *
	 * @param obj Ruby object
	 */
	inline IObject::IObject(VALUE obj) : value(obj)
	{
	}

	/**
	 * @brief Construct a new IObject object from Ruby code
	 *
	 * @param expression Ruby code
	 */
	inline IObject::IObject(std::string_view expression) : value(RubyUtils::exec(expression))
	{
	}

	/**
	 * @brief Gets the raw Ruby object
	 *
	 * @return VALUE Reference to raw Ruby object
	 */
	inline VALUE IObject::to_ruby() const
	{
		return value;
	}

	/**
	 * @brief Check if the wrapped Ruby object is nil
	 *
	 * @return bool true if the object is nil, false otherwise
	 */
	inline bool IObject::is_nil()
	{
		return value == Qnil;
	}

	/**
	 * @brief Wrapper for https://apidock.com/ruby/Object/send
	 *
	 * @tparam T Return type. The Ruby result will be cast to this type
	 * @tparam Args Types of the parameters of the methods. Must be convertible to VALUE
	 * @param func Name of the Ruby methods that is being called.
	 * @param args Parameters for the Ruby methods
	 * @return T Ruby result converted to this type
	 */
	template <typename T, typename... Args> inline T IObject::_send(std::string_view func, Args... args) const
	{
		static_assert(!std::is_same_v<VALUE, T>, "VALUE is alias for unsigned long long, so there is no way to distinct if VALUE or ULL is requested.");
		static_assert(
			true && (std::is_same_v<VALUE, decltype(cpp_to_ruby(std::declval<Args>()))> && ...), "No viable conversion of the arguments to Ruby object.");
		if constexpr (std::is_same_v<T, void>)
		{
			rb_funcall(this->value, rb_intern(func.data()), sizeof...(args), cpp_to_ruby(args)...);
		}
		if constexpr (!std::is_same_v<T, void>)
		{
			return ruby_to_cpp<T>(rb_funcall(this->value, rb_intern(func.data()), sizeof...(args), cpp_to_ruby(args)...));
		}
	}

	/**
	 * @brief Wrapper for https://apidock.com/ruby/Object/send by rescuing all the Ruby errors
	 *
	 * @tparam T Return type. The Ruby result will be cast to this type
	 * @tparam Args Types of the parameters of the methods. Must be convertible to VALUE
	 * @param func Name of the Ruby methods that is being called.
	 * @param args Parameters for the Ruby methods
	 * @return T Ruby result converted to this type
	 */
	template <typename T, typename... Args> inline RubyUtils::optional<T> IObject::_rescued_send(std::string_view func, Args... args) const
	{
		static_assert(!std::is_same_v<VALUE, T>, "VALUE is alias for unsigned long long, so there is no way to distinct if VALUE or ULL is requested.");
		static_assert(
			true && (std::is_same_v<VALUE, decltype(cpp_to_ruby(std::declval<Args>()))> && ...), "No viable conversion of the arguments to Ruby object.");
	
		return RubyUtils::optional<T>(
			RubyUtils::ruby_rescue(
				[&, this]()
				{
					return rb_funcall(this->value, rb_intern(func.data()), sizeof...(args), cpp_to_ruby(args)...); 
				}
			)
		);
	}

	/**
	 * @brief Construct a new IObject object using Ruby constructor
	 *
	 * @tparam T Ruby object types or wrapped Ruby object types
	 * @param klass Name of the Ruby class
	 * @param args Arguments for the constructor
	 */
	template <typename... T> inline IObject::IObject(std::string klass, T... args)
	{
		this->value = rb_funcall(rb_eval_string(klass.c_str()), rb_intern("new"), sizeof...(T), (cpp_to_ruby(args))...);
	}

	/**
	 * @brief Construct a new IObject object using Ruby constructor
	 *
	 * @tparam T Ruby object types or wrapped Ruby object types
	 * @param klass Ruby pointer to class
	 * @param args Arguments for the constructor of the class
	 */
	template <typename... T> inline IObject::IObject(VALUE klass, T... args)
	{
		this->value = rb_funcall(klass, rb_intern("new"), sizeof...(T), (cpp_to_ruby(args))...);
	}

	/**
	 * @brief Wrapper for https://apidock.com/ruby/Object/send
	 *
	 * @tparam Args Types of the parameters of the methods. Must be convertible to VALUE
	 * @param func Name of the Ruby methods that is being called.
	 * @param args Parameters for the Ruby methods
	 * @return VALUE Ruby result converted to this type
	 */
	template <typename... Args> inline VALUE IObject::send(std::string_view func, Args... args)
	{
		static_assert(true && (std::is_convertible_v<VALUE, Args> && ...), "No viable conversion of the arguments to Ruby object.");
		return rb_funcall(this->value, rb_intern(func.data()), sizeof...(args), args...);
	}

	template <typename T> inline std::optional<T> IObject::as() const
	{
		return this->is_a(RubyUtils::get_class<T>()) ? std::make_optional(T(this->to_ruby())) : std::nullopt;
	}

} // namespace RubyUtils
