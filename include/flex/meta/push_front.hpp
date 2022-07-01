#ifndef FLEX_PUSH_FRONT_HPP
#define FLEX_PUSH_FRONT_HPP

namespace flex {
    template<typename TypeList, typename T>
    struct push_front;

    template<template<typename...> typename TypeList, typename... Ts, typename T>
    struct push_front<TypeList<Ts...>, T> {
        using type = TypeList<T, Ts...>;
    };


}

#endif
