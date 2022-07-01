#ifndef FLEX_IGNORE_HPP
#define FLEX_IGNORE_HPP

namespace flex {

    template<typename T>
    struct ignore_value {
        template<auto >
        struct apply {
            using type = T;
        };
    };

    template<typename T>
    struct ignore_type {
        template<typename >
        struct apply {
            using type = T;
        };
    };
}

#endif //FLEX_IGNORE_HPP
