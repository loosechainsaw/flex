#ifndef FLEX_ALL_OF_HPP
#define FLEX_ALL_OF_HPP

#include <type_traits>

namespace flex {
    template<typename TypeList, template<typename> typename Predicate>
    struct any_of;

    template<template<typename... > typename TypeList,
            template<typename> typename Predicate>
    struct any_of<TypeList<>, Predicate>
            : std::false_type
    {
    };

    template<template<typename... > typename TypeList,
             template<typename> typename Predicate,
             typename T,
             typename... Ts>
    struct any_of<TypeList<T, Ts...>, Predicate>
        : std::bool_constant<Predicate<T>::value ||
                             any_of<TypeList<Ts...>, Predicate>::value>
    {

    };
}

#endif
