#ifndef FLEX_POP_FRONT_HPP
#define FLEX_POP_FRONT_HPP

#include <flex/meta/tail.hpp>

namespace flex {

    template<typename T>
    using pop_front = flex::tail<T>;

    template<typename T>
    using pop_front_t = typename pop_front<T>::type;

}

#endif
