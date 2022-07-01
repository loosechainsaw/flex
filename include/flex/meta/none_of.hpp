#ifndef FLEX_NONE_OF_HPP
#define FLEX_NONE_OF_HPP

#include <flex/meta/all_of.hpp>
#include <flex/utility/negate.hpp>

namespace flex {

    template<typename TypeList, template<typename> typename Predicate>
    struct none_of : all_of<TypeList, negate<Predicate>:: template apply> {};
}

#endif
