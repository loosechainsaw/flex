#include <flex/meta/all_of.hpp>
#include <catch/catch.hpp>
#include <tuple>

TEST_CASE("all_of typelist tests") {

    SECTION("empty typelist") {
        using t1 = std::tuple<>;
        REQUIRE(flex::all_of<t1, std::is_const>{});
    }

    SECTION("single entry typelist") {
        using t2 = std::tuple<int const>;
        REQUIRE(flex::all_of<t2, std::is_const>::value);
    }

    SECTION("multiple entry typelist") {
        using t3 = std::tuple<int const, double const>;
        REQUIRE(flex::all_of<t3, std::is_const>::value);
    }
}