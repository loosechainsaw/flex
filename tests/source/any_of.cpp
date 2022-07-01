#include <flex/meta/any_of.hpp>
#include <catch/catch.hpp>
#include <tuple>

TEST_CASE("any_of typelist tests") {

    SECTION("empty typelist") {
        using t1 = std::tuple<>;
        REQUIRE_FALSE(flex::any_of<t1, std::is_const>{});
    }

    SECTION("single entry typelist") {
        using t2 = std::tuple<int const>;
        REQUIRE(flex::any_of<t2, std::is_const>::value);
    }

    SECTION("single entry typelist negative test") {
        using t3 = std::tuple<int>;
        REQUIRE_FALSE(flex::any_of<t3, std::is_const>::value);
    }

    SECTION("multiple entry typelist") {
        using t4 = std::tuple<int const, double>;
        REQUIRE(flex::any_of<t4, std::is_const>::value);
    }

    SECTION("multiple entry typelist negative test") {
        using t5 = std::tuple<int, double>;
        REQUIRE_FALSE(flex::any_of<t5, std::is_const>::value);
    }
}