#ifndef FLEX_COUNT_HPP
#define FLEX_COUNT_HPP

#include <type_traits>

namespace flex {

    template<typename TypeList, typename T>
    struct count;

    template<template<typename... Ts> typename TypeList, typename T>
    struct count<TypeList<>, T> : std::integral_constant<int, 0> { };

    template<template<typename... Ts> typename TypeList, typename... Ts, typename T>
    struct count<TypeList<T, Ts...>, T> : std::integral_constant<int, (1 + count<TypeList<Ts...>, T>::value)> {};

    template<template<typename... Ts> typename TypeList, typename T, typename... Ts, typename U>
    struct count<TypeList<T, Ts...>, U> : count<TypeList<Ts...>, T>::value {};
}

#endif
