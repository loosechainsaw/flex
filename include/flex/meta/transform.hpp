#ifndef FLEX_TRANSFORM_HPP
#define FLEX_TRANSFORM_HPP

namespace flex {
    template<typename TypeList, template<typename> typename Mapper>
    struct transform;

    template<template<typename...> typename TypeList, template<typename> typename Mapper, typename... Ts>
    struct transform<TypeList<Ts...>, Mapper> {
        using type = TypeList<typename Mapper<Ts>::type...>;
    };


}

#endif
