#ifndef FLEX_TRANSFORM_FRONT_HPP
#define FLEX_TRANSFORM_FRONT_HPP

#include <flex/meta/type_identity.hpp>

namespace flex {

    template<typename TypeList, template<typename> typename F>
    struct transform_front;

    template<template<typename...> typename TypeList, template<typename> typename F>
    struct transform_front<TypeList<>, F> : type_identity<TypeList<>> {};

    template<template<typename...> typename TypeList, template<typename> typename F, typename T, typename... Ts>
    struct transform_front<TypeList<T, Ts...>, F> : type_identity<TypeList<typename F<T>::type, Ts...>> {};
}


#endif
