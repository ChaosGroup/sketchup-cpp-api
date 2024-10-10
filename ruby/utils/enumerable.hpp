#pragma once

#include "./object.hpp"

namespace RubyUtils
{

	/**
	 * @brief Wrapper for non-homogeneous Ruby Enumerable objects
	 *
	 */
	class IEnumerable : public details::IObject
	{
		public:
		IEnumerable(VALUE obj);
		IEnumerable(const IObject& obj);
		IEnumerable(IObject&& obj);

		private:
		inline static VALUE each_end(...)
		{
			throw std::out_of_range("StopIteration: Ruby next reached end of enumeration");
		}

		inline static VALUE each_executor(VALUE obj)
		{
			std::pair<VALUE, std::function<void(VALUE)>>* params = reinterpret_cast<std::pair<VALUE, std::function<void(VALUE)>>*>(obj);
			const VALUE enumerator = rb_funcall(params->first, rb_intern("to_enum"), 0);
			while (true)
			{
				VALUE element = rb_funcall(enumerator, rb_intern("next"), 0);
				params->second(element);
			}
			return Qnil;
		}

		public:
		/**
		 * @brief C++ wrapper for https://apidock.com/ruby/v2_5_5/Enumerator/each
		 *
		 * @param lambda block to be called with each element of the enumeration
		 */
		inline void each(std::function<void(VALUE)> lambda);

		/**
		 * @brief C++ wrapper for https://apidock.com/ruby/v2_5_5/Enumerator/each_with_index
		 *
		 * @param lambda block to be called with each element of the enumeration
		 */
		inline void each_with_index(std::function<void(VALUE, size_t)> lambda);

		/**
		 * @brief C++ wrapper for https://apidock.com/ruby/Enumerable/to_a
		 *
		 * @return std::vector<VALUE> Collection of the elements of the enumeration
		 */
		inline std::vector<VALUE> to_a();
	};

	/**
	 * @brief Wrapper for Ruby Enumerable objects
	 *
	 * @tparam T C++ Wrapper class for host app Ruby objects
	 */
	template <typename T> class Enumerable : public IEnumerable
	{
		public:
		using element_t = T;
		inline Enumerable(VALUE obj);
		inline Enumerable(const IObject& obj);
		inline Enumerable(IObject&& obj);

		/**
		 * @brief Construct a new Enumerable object
		 *
		 * @tparam Container should be iterable collection that has overloads for std::begin and std::end
		 * @param elements
		 */
		template <typename Container, typename = std::enable_if_t<!std::is_same_v<VALUE, std::remove_cvref<Container>> && !std::is_same_v<Object, std::remove_cvref<Container>>>> inline Enumerable(Container elements);

		public:
		/**
		 * @brief C++ wrapper for https://apidock.com/ruby/v2_5_5/Enumerator/each
		 *
		 * @param lambda block to be called with each element of the enumeration
		 */
		inline void each(std::function<void(T)> lambda);

		/**
		 * @brief C++ wrapper for https://apidock.com/ruby/v2_5_5/Enumerator/each_with_index
		 *
		 * @param lambda block to be called with each element of the enumeration
		 */
		inline void each_with_index(std::function<void(T, size_t)> lambda);

		public:
		/**
		 * @brief C++ wrapper for https://apidock.com/ruby/Enumerable/to_a
		 *
		 * @return std::vector<T> Collection of the elements of the enumeration
		 */
		inline std::vector<T> to_a();
	};

} // namespace RubyUtils

#include "enumerable.cc"
