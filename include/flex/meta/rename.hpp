#ifndef FLEX_RENAME_HPP
#define FLEX_RENAME_HPP

#include <flex/meta/type_identity.hpp>

namespace flex {

    template<typename F, template<typename...> typename T>
    struct rename;

    template<template<typename...> typename SourceTypeList,
             template<typename...> typename DestSourceList,
             typename... Ts>
    struct rename<SourceTypeList<Ts...>, DestSourceList> {
        using type = DestSourceList<Ts...> ;
    };
}

#endif
