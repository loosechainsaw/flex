#ifndef FLEX_CONCAT_HPP
#define FLEX_CONCAT_HPP

namespace flex {

    template<typename T1, typename T2>
    struct concat;

    template<template<typename... > typename TypeList, typename... Ts, typename... Us >
    struct concat<TypeList<Ts...>, TypeList<Us...>> {
        using type = TypeList<Ts..., Us...>;
    };
}

#endif
