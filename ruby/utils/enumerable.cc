namespace RubyUtils
{

	inline IEnumerable::IEnumerable(VALUE obj) : IObject(obj)
	{
	}
	inline IEnumerable::IEnumerable(const IObject& obj) : IObject(obj)
	{
	}
	inline IEnumerable::IEnumerable(IObject&& obj) : IObject(obj)
	{
	}

	/**
	 * @brief C++ wrapper for https://apidock.com/ruby/v2_5_5/Enumerator/each
	 *
	 * @param lambda block to be called with each element of the enumeration
	 */
	inline void IEnumerable::each(std::function<void(VALUE)> lambda)
	{
		std::pair<VALUE, std::function<void(VALUE)>>* params = new std::pair<VALUE, std::function<void(VALUE)>>(this->value, lambda);
		VALUE ptr = (VALUE)params;
		try
		{
			[[maybe_unused]] VALUE element = rb_rescue2(RUBY_METHOD_FUNC(each_executor), ptr, RUBY_METHOD_FUNC(each_end), Qnil, rb_eStopIteration, 0);
		}
		catch ([[maybe_unused]] std::out_of_range& e)
		{
			delete params;
			return;
		}
		delete params;
	}

	/**
	 * @brief C++ wrapper for https://apidock.com/ruby/v2_5_5/Enumerator/each_with_index
	 *
	 * @param lambda block to be called with each element of the enumeration
	 */
	inline void IEnumerable::each_with_index(std::function<void(VALUE, size_t)> lambda)
	{
		size_t ind = 0;
		this->each([&ind, &lambda](VALUE obj) {
			lambda(obj, ind);
			ind++;
		});
	}

	/**
	 * @brief C++ wrapper for https://apidock.com/ruby/Enumerable/to_a
	 *
	 * @return std::vector<VALUE> Collection of the elements of the enumeration
	 */
	inline std::vector<VALUE> IEnumerable::to_a()
	{
		std::vector<VALUE> answer;
		// TODO: evalute if the following size call is performance optimization or not
		// due to the push_back reallocation of the vector
		answer.reserve(this->_send<unsigned>("size"));
		this->each([&answer](VALUE element) { answer.push_back(element); });
		return answer;
	}

	template <typename T> inline Enumerable<T>::Enumerable(VALUE obj) : IEnumerable(obj)
	{
	}

	template <typename T> inline Enumerable<T>::Enumerable(const IObject& obj) : IEnumerable(obj)
	{
	}

	template <typename T> inline Enumerable<T>::Enumerable(IObject&& obj) : IEnumerable(obj)
	{
	}

	/**
	 * @brief Construct a new Enumerable object
	 *
	 * @tparam Container should be iterable collection that has overloads for std::begin and std::end
	 * @param elements
	 */
	template <typename T> template <typename Container, typename U> inline Enumerable<T>::Enumerable(Container elements) : IEnumerable(Qnil)
	{
		if constexpr (std::is_base_of_v<Enumerable<T>, std::remove_cvref<Container>>)
		{
			this->value = elements.value;
		}
		if constexpr (!std::is_base_of_v<Enumerable<T>, std::remove_cvref<Container>>)
		{
			this->value = rb_ary_new();
			for (auto it = std::begin(elements); it != std::end(elements); it++)
			{
				rb_ary_push(this->value, IObject::cpp_to_ruby(*it));
			}
		}
	}

	/**
	 * @brief C++ wrapper for https://apidock.com/ruby/v2_5_5/Enumerator/each
	 *
	 * @param lambda block to be called with each element of the enumeration
	 */
	template <typename T> inline void Enumerable<T>::each(std::function<void(T)> lambda)
	{
		IEnumerable::each([&lambda](VALUE element) { lambda(T(element)); });
	}

	/**
	 * @brief C++ wrapper for https://apidock.com/ruby/v2_5_5/Enumerator/each_with_index
	 *
	 * @param lambda block to be called with each element of the enumeration
	 */
	template <typename T> inline void Enumerable<T>::each_with_index(std::function<void(T, size_t)> lambda)
	{
		IEnumerable::each_with_index([&lambda](VALUE element, size_t ind) { lambda(T(element, ind)); });
	}

	/**
	 * @brief C++ wrapper for https://apidock.com/ruby/Enumerable/to_a
	 *
	 * @return std::vector<T> Collection of the elements of the enumeration
	 */
	template <typename T> inline std::vector<T> Enumerable<T>::to_a()
	{
		std::vector<T> answer;
		// TODO: evalute if the following size call is performance optimization or not
		// due to the push_back reallocation of the vector
		answer.reserve(this->_send<unsigned>("size"));
		this->each([&answer](T element) { answer.push_back(element); });
		return answer;
	}

} // namespace RubyUtils
