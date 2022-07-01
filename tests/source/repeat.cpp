#include <flex/meta/repeat.hpp>
#include <catch/catch.hpp>
#include <tuple>

TEST_CASE("repeat typelist tests") {

    SECTION("repeat zero times") {
        using t2 = flex::repeat<std::tuple, int, 0>::type;
        using expected = std::tuple<>;
        REQUIRE(std::is_same_v<expected,t2>);
    }

    SECTION("repeat multiple times") {
        using t2 = flex::repeat<std::tuple, int, 3>::type;
        using expected = std::tuple<int, int, int>;
        REQUIRE(std::is_same_v<t2,expected>);
    }

}