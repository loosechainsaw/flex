#ifndef FLEX_FIND_HPP
#define FLEX_FIND_HPP

#include <type_traits>

namespace flex {

    namespace detail {

        template<typename TypeList, typename T, int Index>
        struct find;

        template<template<typename...> typename TypeList, typename T, int Index>
        struct find<TypeList<>, T, Index> : std::integral_constant<int, -1> { };

        template<template<typename...> typename TypeList, int Index, typename T, typename... Ts>
        struct find<TypeList<T, Ts...>, T, Index> : std::integral_constant<int, Index> {};

        template<template<typename...> typename TypeList, int Index, typename T, typename U, typename... Us>
        struct find<TypeList<U, Us...>, T, Index> : find<TypeList<Us...>, T, Index + 1> {};
    }

    template<typename TypeList, typename T>
    struct find;

    template<template<typename... Ts> typename TypeList, typename... Ts, typename T>
    struct find<TypeList<Ts...>, T> : detail::find<TypeList<Ts...>, T, 0>  {};
}

#endif
