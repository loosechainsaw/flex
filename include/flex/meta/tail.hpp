#ifndef FLEX_TAIL_HPP
#define FLEX_TAIL_HPP

namespace flex {

    template<typename TypeList>
    struct tail;

    template<template<typename...> typename TypeList>
    struct tail<TypeList<>> {
        using type = TypeList<>;
    };

    template<template<typename...> typename TypeList, typename T, typename... Ts>
    struct tail<TypeList<T, Ts...>> {
        using type = TypeList<Ts...>;
    };

    template<typename T>
    using tail_t = typename tail<T>::type;

}

#endif
