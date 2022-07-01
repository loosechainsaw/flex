#include <flex/meta/third.hpp>
#include <catch/catch.hpp>
#include <tuple>

TEST_CASE("third typelist tests") {

    SECTION("empty typelist") {
        using t1 = std::tuple<>;
        using t2 = flex::third<t1>::type;
        REQUIRE(std::is_same_v<flex::nil,t2>);
    }

    SECTION("single entry typelist") {
        using t1 = std::tuple<int>;
        using t2 = flex::third<t1>::type;
        REQUIRE(std::is_same_v<t2,flex::nil>);
    }

    SECTION("two entry typelist") {
        using t1 = std::tuple<int, double>;
        using t2 = flex::third<t1>::type;
        REQUIRE(std::is_same_v<t2,flex::nil>);
    }

    SECTION("three entry typelist") {
        using t1 = std::tuple<int, double, long>;
        using t2 = flex::third<t1>::type;
        REQUIRE(std::is_same_v<t2,long>);
    }
}