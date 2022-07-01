#ifndef FLEX_COPY_HPP
#define FLEX_COPY_HPP

namespace flex {

    template<typename T>
    struct copy;

    template<template<typename...> typename TypeList, typename... Ts>
    struct copy<TypeList<Ts...>> {
        using type = TypeList<Ts...>;
    };
}

#endif
