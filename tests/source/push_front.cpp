#include <flex/meta/push_front.hpp>
#include <catch/catch.hpp>
#include <tuple>

TEST_CASE("push_front typelist tests") {

    SECTION("empty typelist") {
        using t1 = std::tuple<>;
        using t2 = flex::push_front<t1, int>::type;
        using expected = std::tuple<int>;
        REQUIRE(std::is_same_v<t2, expected>);
    }

    SECTION("single entry typelist") {
        using t1 = std::tuple<int>;
        using t2 = flex::push_front<t1, double>::type;
        using expected = std::tuple<double, int >;
        REQUIRE(std::is_same_v<t2,expected>);
    }

    SECTION("multiple entry typelist") {
        using t1 = std::tuple<int, double>;
        using t2 = flex::push_front<t1, char>::type;
        using expected = std::tuple<char, int, double>;
        REQUIRE(std::is_same_v<t2,expected>);
    }
}