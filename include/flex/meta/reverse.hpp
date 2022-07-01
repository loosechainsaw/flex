#ifndef FLEX_REVERSE_HPP
#define FLEX_REVERSE_HPP

#include <flex/meta/push_back.hpp>

namespace flex {

    template<typename TypeList>
    struct reverse;

    template<template<typename... > typename TypeList>
    struct reverse<TypeList<>> {
        using type = TypeList<>;
    };

    template<template<typename... > typename TypeList, typename T>
    struct reverse<TypeList<T>> {
        using type = TypeList<T>;
    };

    template<template<typename... > typename TypeList, typename T, typename... Ts>
    struct reverse<TypeList<T, Ts...>> {
        using type = typename push_back<typename reverse<Ts...>::type, T>::type;
    };

}

#endif
