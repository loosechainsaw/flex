#include <flex/meta/find.hpp>
#include <catch/catch.hpp>
#include <tuple>

TEST_CASE("find typelist tests") {

    SECTION("empty typelist") {
        using typelist = std::tuple<>;
        auto v = flex::find<typelist, int>::value;
        REQUIRE(v == -1);
    }

    SECTION("single entry typelist") {
        using typelist = std::tuple<int>;
        auto v = flex::find<typelist, int>::value;
        REQUIRE(v == 0);
    }

    SECTION("single entry typelist negative test") {
        using typelist = std::tuple<int, double>;
        auto v = flex::find<typelist, char>::value;
        REQUIRE(v == -1);
    }

    SECTION("multiple entry typelist") {
        using typelist = std::tuple<double, int>;
        auto v = flex::find<typelist, int>::value;
        REQUIRE(v == 1);
    }

    SECTION("multiple entry typelist negative test") {
        using typelist = std::tuple<long, int>;
        auto v = flex::find<typelist, double>::value;
        REQUIRE(v == -1);
    }
}
