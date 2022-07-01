#ifndef FLEX_COPY_IF_HPP
#define FLEX_COPY_IF_HPP

#include <flex/meta/type_identity.hpp>
#include <flex/meta/push_front.hpp>
#include <type_traits>

namespace flex {

    template<typename T, template<typename > typename Predicate>
    struct copy_if;

    template<template<typename...> typename TypeList, template<typename > typename Predicate>
    struct copy_if<TypeList<>, Predicate> :
                    type_identity<TypeList<>> {};

    template<template<typename...> typename TypeList, typename T, template<typename > typename Predicate>
    struct copy_if<TypeList<T>, Predicate> :
        std::conditional<Predicate<T>::value,
                         type_identity<TypeList<T>>,
                         type_identity<TypeList<>>>::type {};


    template<template<typename...> typename TypeList, typename T, typename... Ts, template<typename > typename Predicate>
    struct copy_if<TypeList<T, Ts...>, Predicate> :
            std::conditional<Predicate<T>::value,
                             push_front<typename copy_if<TypeList<Ts...>, Predicate>::type, T>,
                             copy_if<TypeList<Ts...>, Predicate>>::type {};
}

#endif
