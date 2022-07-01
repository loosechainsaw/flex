#ifndef FLEX_FIRST_HPP
#define FLEX_FIRST_HPP

#include <flex/meta/front.hpp>

namespace flex {

    template<typename T>
    using first = front<T>;

    template<typename T>
    using first_t = typename first<T>::type;

}

#endif
