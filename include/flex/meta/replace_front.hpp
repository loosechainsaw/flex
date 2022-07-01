#ifndef FLEX_REPLACE_FRONT_HPP
#define FLEX_REPLACE_FRONT_HPP

#include <flex/meta/type_identity.hpp>

namespace flex {

    template<typename TypeList, typename T>
    struct replace_front;

    template<template<typename...> typename TypeList, typename T, typename... Us>
    struct replace_front<TypeList<Us...>, T> : type_identity<TypeList<T, Us...>> {};

    template<template<typename...> typename TypeList, typename T, typename U, typename... Us>
    struct replace_front<TypeList<U, Us...>, T> : type_identity<TypeList<T, Us...>> {};
}

#endif
