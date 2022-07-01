#ifndef FLEX_TYPE_IDENTITY_HPP
#define FLEX_TYPE_IDENTITY_HPP

namespace flex {
    template<typename T>
    struct type_identity {
        using type = T;
    };
}

#endif
