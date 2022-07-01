#include <flex/meta/replace_front.hpp>
#include <catch/catch.hpp>
#include <tuple>

TEST_CASE("replace_front typelist tests") {

    SECTION("empty typelist") {
        using t1 = std::tuple<>;
        using t2 = flex::replace_front<t1, int>::type;
        using expected = std::tuple<int>;
        REQUIRE(std::is_same_v<expected,t2>);
    }

    SECTION("single entry typelist") {
        using t1 = std::tuple<int>;
        using t2 = flex::replace_front<t1, float>::type;
        using expected = std::tuple<float>;
        REQUIRE(std::is_same_v<t2,expected>);
    }

    SECTION("multiple entry typelist") {
        using t1 = std::tuple<int, double>;
        using t2 = flex::replace_front<t1, float>::type;
        using expected = std::tuple<float, double>;
        REQUIRE(std::is_same_v<t2,expected>);
    }
}