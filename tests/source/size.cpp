#include <catch/catch.hpp>
#include <flex/meta/size.hpp>
#include <tuple>

TEST_CASE("size typelist tests") {

    SECTION("empty typelist") {
        using t1 = std::tuple<>;
        REQUIRE_FALSE(flex::size<t1>{});
    }

    SECTION("single entry typelist") {
        using t2 = std::tuple<int>;
        REQUIRE(flex::size<t2>::value == 1);
    }

    SECTION("multiple entry typelist") {
        using t3 = std::tuple<int, double>;
        REQUIRE(flex::size<t3>::value == 2);
    }
}