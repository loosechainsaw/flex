#include <flex/meta/clear.hpp>
#include <catch/catch.hpp>
#include <tuple>

TEST_CASE("clear typelist tests") {

    SECTION("empty typelist") {
        using t1 = std::tuple<>;
        using t2 = flex::clear<t1>::type;
        REQUIRE(std::is_same_v<t1,t2>);
    }

    SECTION("single entry typelist") {
        using t1 = std::tuple<int>;
        using t2 = flex::clear<t1>::type;
        using expected = std::tuple<>;
        REQUIRE(std::is_same_v<t2,expected>);
    }

    SECTION("alias test") {
        using t1 = std::tuple<int>;
        using t2 = flex::clear_t<t1>;
        using expected = std::tuple<>;
        REQUIRE(std::is_same_v<t2,expected>);
    }

    SECTION("multiple entry typelist") {
        using t1 = std::tuple<int, double>;
        using t2 = flex::clear<t1>::type;
        using expected = std::tuple<>;
        REQUIRE(std::is_same_v<t2,expected>);
    }
}