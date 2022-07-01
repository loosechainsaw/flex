#ifndef FLEX_NEGATE_HPP
#define FLEX_NEGATE_HPP

namespace flex {

    template<template<typename> typename Predicate>
    struct negate{
        template<typename T>
        struct apply {
            static constexpr bool value = !Predicate<T>::value;
        };
    };
}

#endif
