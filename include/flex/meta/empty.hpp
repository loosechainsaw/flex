#ifndef FLEX_EMPTY_HPP
#define FLEX_EMPTY_HPP

#include <type_traits>

namespace flex {

    template<typename T>
    struct empty;

    template<template<typename... > typename TypeList>
    struct empty<TypeList<>> : std::true_type {};

    template<template<typename... > typename TypeList, typename... Ts>
    struct empty<TypeList<Ts...>> : std::false_type {};
}

#endif
