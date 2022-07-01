#include <flex/meta/copy_if.hpp>
#include <catch/catch.hpp>
#include <tuple>

TEST_CASE("copy_if typelist tests") {

    SECTION("empty typelist") {
        using t1 = std::tuple<>;
        using t2 = flex::copy_if<t1, std::is_const>::type;
        REQUIRE(std::is_same_v<t1,t2>);
    }

    SECTION("single entry typelist") {
        using t1 = std::tuple<int>;
        using t2 = flex::copy_if<t1, std::is_const>::type;
        using expected = std::tuple<>;
        REQUIRE(std::is_same_v<t2,expected>);
    }

    SECTION("single entry typelist matching") {
        using t1 = std::tuple<const int>;
        using t2 = flex::copy_if<t1, std::is_const>::type;
        using expected = std::tuple<const int>;
        REQUIRE(std::is_same_v<t2,expected>);
    }

    SECTION("multiple entry typelist negative") {
        using t1 = std::tuple<int, double>;
        using t2 = flex::copy_if<t1, std::is_const>::type;
        using expected = std::tuple<>;
        REQUIRE(std::is_same_v<t2,expected>);
    }

    SECTION("multiple entry typelist partial") {
        using t1 = std::tuple<int, const double>;
        using t2 = flex::copy_if<t1, std::is_const>::type;
        using expected = std::tuple<const double>;
        REQUIRE(std::is_same_v<t2,expected>);
    }

    SECTION("multiple entry typelist matching") {
        using t1 = std::tuple<const int, const double>;
        using t2 = flex::copy_if<t1, std::is_const>::type;
        using expected = std::tuple<const int, const double>;
        REQUIRE(std::is_same_v<t2,expected>);
    }
}