#include <flex/meta/find_if.hpp>
#include <catch/catch.hpp>
#include <tuple>

TEST_CASE("find_if typelist tests") {

    SECTION("empty typelist") {
        using typelist = std::tuple<>;
        auto v = flex::find_if<typelist, std::is_const>::value;
        REQUIRE(v == -1);
    }

    SECTION("single entry typelist") {
        using typelist = std::tuple<int>;
        auto v = flex::find_if<typelist, std::is_integral>::value;
        REQUIRE(v == 0);
    }

    SECTION("single entry typelist negative test") {
        using typelist = std::tuple<int>;
        auto v = flex::find_if<typelist, std::is_floating_point>::value;
        REQUIRE(v == -1);
    }

    SECTION("multiple entry typelist") {
        using typelist = std::tuple<double, int>;
        auto v = flex::find_if<typelist, std::is_integral>::value;
        REQUIRE(v == 1);
    }

    SECTION("multiple entry typelist negative test") {
        using typelist = std::tuple<long, int>;
        auto v = flex::find_if<typelist, std::is_floating_point>::value;
        REQUIRE(v == -1);
    }
}
