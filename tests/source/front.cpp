#include <flex/meta/front.hpp>
#include <catch/catch.hpp>
#include <tuple>

TEST_CASE("front typelist tests") {

    SECTION("empty typelist") {
        using t1 = std::tuple<>;
        using t2 = flex::front<t1>::type;
        REQUIRE(std::is_same_v<flex::nil,t2>);
    }

    SECTION("single entry typelist") {
        using t1 = std::tuple<int>;
        using t2 = flex::front<t1>::type;
        REQUIRE(std::is_same_v<t2,int>);
    }

    SECTION("multiple entry typelist") {
        using t1 = std::tuple<int, double>;
        using t2 = flex::front<t1>::type;
        REQUIRE(std::is_same_v<t2,int>);
    }
}