#pragma once

#define ADD_HANDLER_FOR(class_name, event, bitcode, ...) \
    if (bitmask & (decltype(bitmask))bitcode) \
        set_##event(cpp_utils::mem_bind_front(& class_name :: event, this));

#define INIT_HANDLER_FOR_EVENT(class_name, event, ret_type, signature, args, params) \
private: \
    std::function<ret_type signature> _##event; \
    static inline VALUE static_##event args { \
        static_cast<std::shared_ptr<class_name>*>(DATA_PTR(self))->get()->_##event params ; \
        return Qnil; \
    } \
public: \
    virtual inline ret_type event signature { } \
    inline class_name& set_##event(std::function<ret_type signature> func) \
    { \
        if (value == Qnil) return *this; \
        _##event = func; \
        rb_define_singleton_method(value, #event, RUBY_METHOD_FUNC(static_##event), COUNT_ARGS<ret_type signature>::value); \
        return *this; \
    }

template<typename T>
class COUNT_ARGS;

template<typename ret_type, typename... Ts>
class COUNT_ARGS<ret_type(Ts...)> {
    public:
    static constexpr int value = (int)sizeof...(Ts);
};
