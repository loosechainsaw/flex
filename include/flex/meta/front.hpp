#ifndef FLEX_FRONT_HPP
#define FLEX_FRONT_HPP

#include "flex/ds/nil.hpp"
#include <flex/meta/type_identity.hpp>
#include <type_traits>

namespace flex {

    template<typename TypeList>
    struct front;

    template<template <typename...> typename TypeList>
    struct front<TypeList<>> : type_identity<nil> {};

    template<template <typename...> typename TypeList, typename T, typename... Ts>
    struct front<TypeList<T, Ts...>> : type_identity<T> {};
}

#endif
