#ifndef FLEX_FIND_IF_HPP
#define FLEX_FIND_IF_HPP

#include <type_traits>

namespace flex {

    namespace detail {

        template<typename TypeList, template<typename> typename Predicate, int Index>
        struct find_if;

        template<template<typename...> typename TypeList, template<typename> typename Predicate, int Index>
        struct find_if<TypeList<>, Predicate, Index> : std::integral_constant<int, -1> { };

        template<template<typename...> typename TypeList, template<typename> typename Predicate, int Index, typename T, typename... Ts>
        struct find_if<TypeList<T, Ts...>, Predicate, Index>
            :  std::conditional<Predicate<T>::value,
                               std::integral_constant<int, Index>,
                               find_if<TypeList<Ts...>, Predicate, Index + 1 >>::type
        {

        };
    }

    template<typename TypeList, template<typename> typename Predicate>
    struct find_if : detail::find_if<TypeList, Predicate, 0> {};

}

#endif
