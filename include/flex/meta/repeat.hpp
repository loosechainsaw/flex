#ifndef FLEX_REPEAT_HPP
#define FLEX_REPEAT_HPP

#include <flex/meta/type_identity.hpp>
#include <flex/utility/ignore.hpp>
#include <cstddef>
#include <utility>

namespace flex {

    namespace detail {

        template<template<typename... > typename TypeList, typename S, typename T>
        struct repeat_;

        template<template<typename...> typename TypeList,
                 typename T,
                 size_t... Indices>
        struct repeat_<TypeList, std::index_sequence<Indices...>, T> :
            type_identity<TypeList<typename ignore_value<T>::template apply<Indices>::type ...>>  { };
    }

    template<template<typename... > typename TypeList, typename T, size_t N>
    struct repeat : detail::repeat_<TypeList, std::make_integer_sequence<size_t, N>, T> {};

}

#endif
