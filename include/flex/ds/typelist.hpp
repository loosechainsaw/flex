#ifndef FLEX_TYPELIST_HPP
#define FLEX_TYPELIST_HPP

#include <type_traits>

namespace flex {

    template<typename... Ts>
    struct typelist {};

    template<typename T, T... Vs>
    using typelist_c = typelist<std::integral_constant<T, Vs>...>;

    template<int... Vs>
    using typelist_int = typelist_c<int, Vs...>;

    template<size_t... Vs>
    using typelist_size_t = typelist_c<size_t, Vs...>;
}

#endif
