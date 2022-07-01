#include <flex/meta/empty.hpp>
#include <catch/catch.hpp>
#include <tuple>

TEST_CASE("empty typelist tests") {

    SECTION("empty typelist") {
        using t1 = std::tuple<>;
        REQUIRE(flex::empty<t1>{});
    }

    SECTION("single entry typelist") {
        using t2 = std::tuple<int const>;
        REQUIRE_FALSE(flex::empty<t2>::value);
    }

    SECTION("multiple entry typelist") {
        using t4 = std::tuple<int const, double>;
        REQUIRE_FALSE(flex::empty<t4>::value);
    }

}