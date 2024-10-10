#pragma once

#define DEFINE_WRAPPED_METHOD_0(ret_type, cpp_name, ruby_name) inline ret_type cpp_name();

#define DEFINE_WRAPPED_METHOD(ret_type, cpp_name, cpp_args, ruby_name, ...) inline ret_type cpp_name cpp_args;

#define IMPLEMENT_WRAPPED_METHOD_0(class_name, ret_type, cpp_name, ruby_name) \
	inline ret_type class_name::cpp_name() \
	{ \
		return this->_send<ret_type>(#ruby_name); \
	}

#define IMPLEMENT_WRAPPED_METHOD(class_name, ret_type, cpp_name, cpp_args, ruby_name, ...) \
	inline ret_type class_name::cpp_name cpp_args \
	{ \
		return this->_send<ret_type>(#ruby_name, __VA_ARGS__); \
	}

#define IMPLEMENT_WRAPPED_METHOD_RESCUED(class_name, ret_type, cpp_name, cpp_args, ruby_name, ...) \
	inline RubyUtils::optional<ret_type> class_name::cpp_name cpp_args \
	{ \
		return this->_rescued_send<ret_type>(#ruby_name, __VA_ARGS__); \
	}

#define DEFINE_WRAPPED_METHOD_COMMA ,
