#ifndef FLEX_NONE_OF_HPP
#define FLEX_NONE_OF_HPP

#include <flex/meta/all_of.hpp>

namespace flex {

    namespace detail {
        template<template<typename> typename Predicate>
        struct negate{
             template<typename T>
             struct apply {
                 static constexpr bool value = !Predicate<T>::value;
             };
        };
    };

    template<typename TypeList, template<typename> typename Predicate>
    struct none_of : all_of<TypeList, detail::negate<Predicate>:: template apply> {};
}

#endif
