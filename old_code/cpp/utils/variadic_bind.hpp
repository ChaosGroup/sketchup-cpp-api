/**
 * @file variadic_bind.hpp
 * @author Alex Tsvetanov (alex.tsvetanov@chaos.com)
 * @brief This code allows calls of std::bind without explicitly specifying all the parameters. Only the front parameters that are replaced with actual values are required.
 * @version 0.1
 * @date 2024-05-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <functional>

namespace cpp_utils {
    template<int...> struct int_sequence {};

    template<int N, int... Is> struct make_int_sequence : make_int_sequence<N - 1, N - 1, Is...> {};
    
    template<int... Is> struct make_int_sequence<0, Is...> : int_sequence<Is...> {};
    
    template<int>
    struct placeholder_template {};
}

namespace std
{
    template<int N>
    struct is_placeholder< cpp_utils::placeholder_template<N> > : integral_constant<int, N + 1> {};
}

namespace cpp_utils {
    template<class F, class... bindings_t, int... Is>
    auto _bind(F&& p, int_sequence<Is...>, bindings_t... bindings)
    {
        return std::bind(p, bindings..., placeholder_template<Is>{}...);
    }

    template<class Ret, class... Args, class... bindings_t>
    auto bind_front(std::function<Ret(Args...)> p, bindings_t... bindings)
    {
        return _bind(p, make_int_sequence< (sizeof...(Args) - sizeof...(bindings_t)) >{}, bindings...);
    }

    template<class Class, class Ret, class... Args, class... bindings_t>
    auto mem_bind_front(Ret(Class::*f)(Args...), bindings_t... bindings)
    {
        std::function<Ret(Class*, Args...)> p = f;
        return _bind(p, make_int_sequence< (sizeof...(Args) - sizeof...(bindings_t) + 1) >{}, bindings...);
    }
}