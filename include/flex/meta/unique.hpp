#ifndef FLEX_UNIQUE_HPP
#define FLEX_UNIQUE_HPP

#include <flex/meta/push_front.hpp>

namespace flex {

    template<typename TypeList>
    struct unique;

    template<template<typename... > typename TypeList>
    struct unique<TypeList<>> {
        using type = TypeList<>;
    };

    template<template<typename... > typename TypeList, typename T>
    struct unique<TypeList<T>> {
        using type = TypeList<T>;
    };

    template<template<typename... > typename TypeList,typename T, typename... Ts>
    struct unique<TypeList<T, T, Ts...>> {
        using type = typename unique<TypeList<Ts...>>::type;
    };

    template<template<typename... > typename TypeList, typename S, typename T, typename... Ts>
    struct unique<TypeList<S, T, Ts...>> {
        using type = typename push_front<S, typename unique<TypeList<T, Ts...>>::type>::type;
    };
 
}

#endif
