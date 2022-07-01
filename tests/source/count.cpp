#include <catch/catch.hpp>
#include <flex/meta/count.hpp>
#include <tuple>

TEST_CASE("count typelist tests") {

    SECTION("empty typelist") {
        using t1 = std::tuple<>;
        REQUIRE(flex::count<t1, int>::value == 0);
    }

    SECTION("single entry typelist") {
        using t2 = std::tuple<int>;
        REQUIRE(flex::count<t2, int>::value == 1);
    }

    SECTION("multiple entry typelist") {
        using t3 = std::tuple<int, int>;
        REQUIRE(flex::count<t3, int>::value == 2);
    }
}