#ifndef FLEX_COUNT_IF_HPP
#define FLEX_COUNT_IF_HPP

#include <type_traits>

namespace flex {

    template<typename TypeList, template<typename> typename Predicate>
    struct count_if;

    template<template<typename... Ts> typename TypeList, template<typename> typename Predicate>
    struct count_if<TypeList<>, Predicate> : std::integral_constant<int, 0> { };

    template<template<typename... Ts> typename TypeList, typename T, typename... Ts, template<typename> typename Predicate>
    struct count_if<TypeList<T, Ts...>, Predicate> :
                 std::conditional<Predicate<T>::value,
                    std::integral_constant<int, 1 + count_if<TypeList<Ts...>, Predicate>::value>,
                    count_if<TypeList<Ts...>, Predicate>>::type
    {
    };


}

#endif
