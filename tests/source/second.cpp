#include <flex/meta/second.hpp>
#include <catch/catch.hpp>
#include <tuple>

TEST_CASE("second typelist tests") {

    SECTION("empty typelist") {
        using t1 = std::tuple<>;
        using t2 = flex::second<t1>::type;
        REQUIRE(std::is_same_v<flex::nil,t2>);
    }

    SECTION("single entry typelist") {
        using t1 = std::tuple<int>;
        using t2 = flex::second<t1>::type;
        REQUIRE(std::is_same_v<t2,flex::nil>);
    }

    SECTION("multiple entry typelist") {
        using t1 = std::tuple<int, double>;
        using t2 = flex::second<t1>::type;
        REQUIRE(std::is_same_v<t2,double>);
    }
}