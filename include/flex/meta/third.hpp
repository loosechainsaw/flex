#ifndef FLEX_THIRD_HPP
#define FLEX_THIRD_HPP

#include <flex/meta/front.hpp>
#include <flex/meta/tail.hpp>

namespace flex {

    template<typename T>
    using third = front<tail_t<tail_t<T>>>;

    template<typename T>
    using third_t = typename third<T>::type;
}

#endif
