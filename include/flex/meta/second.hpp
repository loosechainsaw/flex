#ifndef FLEX_SECOND_HPP
#define FLEX_SECOND_HPP

#include <flex/meta/front.hpp>
#include <flex/meta/tail.hpp>

namespace flex {

    template<typename T>
    using second = front<typename tail<T>::type>;

    template<typename T>
    using second_t = typename second<T>::type;

}

#endif
