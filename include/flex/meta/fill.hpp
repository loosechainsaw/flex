#ifndef FLEX_FILL_HPP
#define FLEX_FILL_HPP

#include <flex/meta/transform.hpp>
#include <flex/meta/type_identity.hpp>

namespace flex {

    namespace detail {
        template<typename T>
        struct second_type {
            template<typename U>
            struct apply {
                using type = T;
            };
        };
    }

    template<typename TypeList, typename T>
    struct fill;

    template<template<typename...> typename TypeList, typename... Ts, typename U>
    struct fill<TypeList<Ts...>, U> : transform<TypeList<Ts...>,
                                                detail::second_type<U>::template apply> {};

}

#endif
