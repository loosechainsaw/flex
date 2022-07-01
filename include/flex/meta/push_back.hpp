#ifndef FLEX_PUSH_BACK_HPP
#define FLEX_PUSH_BACK_HPP

namespace flex {
    template<typename TypeList, typename T>
    struct push_back;

    template<template<typename...> typename TypeList, typename... Ts, typename T>
    struct push_back<TypeList<Ts...>, T> {
        using type = TypeList<Ts..., T>;
    };


}

#endif
