#pragma once

#include <ruby.h>

#include <string>
#include <vector>
#include <map>
#include <optional>
#include <variant>
#include <type_traits>
#include <stdexcept>

namespace SketchUpCppAPI
{

	class Object
	{
	public:
		VALUE self = Qnil;
		Object() = default;
		Object(VALUE v) : self(v) {}
	};

	inline VALUE to_ruby(bool v) { return v ? Qtrue : Qfalse; }
	inline VALUE to_ruby(long v) { return LONG2NUM(v); }
	inline VALUE to_ruby(double v) { return DBL2NUM(v); }
	inline VALUE to_ruby(const char* v) { return rb_str_new_cstr(v); }
	inline VALUE to_ruby(const std::string& v) { return rb_str_new_cstr(v.c_str()); }
	template<typename T> requires requires(T t) { t.self; }
	inline VALUE to_ruby(const T& v) { return v.self; }

	template<typename T> struct is_optional : std::false_type {};
	template<typename T> struct is_optional<std::optional<T>> : std::true_type {};
	template<typename T> struct is_vector : std::false_type {};
	template<typename T> struct is_vector<std::vector<T>> : std::true_type {};
	template<typename T> struct is_variant : std::false_type {};
	template<typename... Ts> struct is_variant<std::variant<Ts...>> : std::true_type {};

	template<typename T>
	inline T from_ruby(VALUE val)
	{
		if constexpr (is_optional<T>::value) {
			if (val == Qnil) return std::nullopt;
			return from_ruby<typename T::value_type>(val);
		}
		else if constexpr (is_vector<T>::value) {
			long len = RARRAY_LEN(val);
			T result;
			result.reserve(len);
			for (long i = 0; i < len; i++)
				result.push_back(from_ruby<typename T::value_type>(rb_ary_entry(val, i)));
			return result;
		}
		else if constexpr (is_variant<T>::value) {
			return T{};
		}
		else if constexpr (std::is_same_v<T, bool>) return RTEST(val);
		else if constexpr (std::is_same_v<T, long>) return NUM2LONG(val);
		else if constexpr (std::is_same_v<T, double>) return NUM2DBL(val);
		else if constexpr (std::is_same_v<T, std::string>) return std::string(StringValueCStr(val));
		else if constexpr (std::is_same_v<T, const char*>) return rb_id2name(SYM2ID(val));
		else return T(val);
	}

	struct ruby_error : std::runtime_error {
		using std::runtime_error::runtime_error;
	};

	template<typename Fn>
	inline auto protect(Fn fn) -> decltype(fn())
	{
		using R = decltype(fn());
		if constexpr (std::is_void_v<R>) {
			int state = 0;
			rb_protect([](VALUE data) -> VALUE {
				(*reinterpret_cast<Fn*>(data))();
				return Qnil;
			}, reinterpret_cast<VALUE>(&fn), &state);
			if (state) {
				VALUE err = rb_errinfo();
				rb_set_errinfo(Qnil);
				VALUE msg = rb_obj_as_string(err);
				throw ruby_error(std::string(StringValueCStr(msg)));
			}
		} else {
			R result{};
			struct Ctx { Fn* fn; R* out; };
			Ctx ctx{&fn, &result};
			int state = 0;
			rb_protect([](VALUE data) -> VALUE {
				auto* c = reinterpret_cast<Ctx*>(data);
				*(c->out) = (*(c->fn))();
				return Qnil;
			}, reinterpret_cast<VALUE>(&ctx), &state);
			if (state) {
				VALUE err = rb_errinfo();
				rb_set_errinfo(Qnil);
				VALUE msg = rb_obj_as_string(err);
				throw ruby_error(std::string(StringValueCStr(msg)));
			}
			return result;
		}
	}

}
