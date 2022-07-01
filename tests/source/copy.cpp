#include <flex/meta/copy.hpp>
#include <catch/catch.hpp>
#include <tuple>

TEST_CASE("copy typelist tests") {

    SECTION("empty typelist") {
        using t1 = std::tuple<>;
        using t2 = flex::copy<t1>::type;
        REQUIRE(std::is_same_v<t1,t2>);
    }

    SECTION("single entry typelist") {
        using t1 = std::tuple<int>;
        using t2 = flex::copy<t1>::type;
        REQUIRE(std::is_same_v<t1,t2>);
    }

    SECTION("multiple entry typelist") {
        using t1 = std::tuple<int, double>;
        using t2 = flex::copy<t1>::type;
        REQUIRE(std::is_same_v<t1,t2>);
    }
}