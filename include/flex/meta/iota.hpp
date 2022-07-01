#ifndef FLEX_IOTA_HPP
#define FLEX_IOTA_HPP

#include <flex/meta/type_identity.hpp>
#include <cstddef>
#include <utility>

namespace flex {

    namespace detail {

        template<typename T, typename S>
        struct iota_;

        template<template<typename...> typename TypeList,
                 typename... Ts,
                 size_t... Indices>
        struct iota_<TypeList<Ts...>, std::index_sequence<Indices...>> : type_identity<TypeList<std::integral_constant<size_t, Indices>...>>  { };
    }

    template<typename T, size_t N>
    struct iota;

    template<template<typename...> typename TypeList, size_t N>
    struct iota<TypeList<>, N> : detail::iota_<TypeList<>, std::make_integer_sequence<size_t ,N>> {};

}

#endif
