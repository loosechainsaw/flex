#ifndef FLEX_SIZE_HPP
#define FLEX_SIZE_HPP

#include <type_traits>

namespace flex {
    template<typename TypeList>
    struct size;

    template<template<typename...> typename TypeList>
    struct size<TypeList<>> : std::integral_constant<int, 0> { };

    template<template<typename...> typename TypeList, typename T, typename... Ts>
    struct size<TypeList<T, Ts...>> : std::integral_constant<int, (1 + size<TypeList<Ts...>>::value)> {};

}

#endif
