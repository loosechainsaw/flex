#ifndef FLEX_CLEAR_HPP
#define FLEX_CLEAR_HPP

namespace flex {

    template<typename T>
    struct clear;

    template<template<typename...> typename TypeList, typename... Ts>
    struct clear<TypeList<Ts...>> {
        using type = TypeList<>;
    };

    template<typename T>
    using clear_t = typename clear<T>::type;

}

#endif
