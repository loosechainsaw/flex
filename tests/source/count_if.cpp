#include <catch/catch.hpp>
#include <flex/meta/count_if.hpp>
#include <tuple>

TEST_CASE("count if typelist tests") {

    SECTION("empty typelist") {
        using t1 = std::tuple<>;
        REQUIRE(flex::count_if<t1, std::is_const>::value == 0);
    }

    SECTION("single entry typelist") {
        using t2 = std::tuple<int const>;
        REQUIRE(flex::count_if<t2, std::is_const>::value == 1);
    }

    SECTION("multiple entry typelist") {
        using t3 = std::tuple<int const, int const>;
        REQUIRE(flex::count_if<t3, std::is_const>::value == 2);
    }
}