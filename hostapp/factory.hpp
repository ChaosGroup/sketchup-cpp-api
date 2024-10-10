#pragma once

#include "../ruby/utils.hpp"
#include <memory>

// Will create a ruby instance wrapping and having shared ownership of the object in question
template <typename T, typename... Args> std::shared_ptr<T> make_ruby(Args&&... args)
{
	auto destructor = [](void* p) { delete static_cast<std::shared_ptr<T>*>(p); };
	VALUE value = Data_Wrap_Struct(rb_cObject, 0, destructor, nullptr);
	std::shared_ptr<T> cpp_obj(new T(std::forward<Args>(args)...));
	cpp_obj->bind(value);
	DATA_PTR(value) = new std::shared_ptr<T>(cpp_obj);
	return cpp_obj;
}

