#include <flex/meta/transform.hpp>
#include <catch/catch.hpp>
#include <tuple>

TEST_CASE("transform typelist tests") {

    SECTION("empty typelist") {
        using t1 = std::tuple<>;
        using t2 = flex::transform<t1, std::add_const>::type;
        REQUIRE(std::is_same_v<t1,t2>);
    }

    SECTION("single entry typelist") {
        using t1 = std::tuple<int>;
        using t2 = flex::transform<t1, std::add_const>::type;
        using expected = std::tuple<int const>;
        REQUIRE(std::is_same_v<t2,expected>);
    }

    SECTION("multiple entry typelist") {
        using t1 = std::tuple<int, double>;
        using t2 = flex::transform<t1, std::add_const>::type;
        using expected = std::tuple<int const, double const>;
        REQUIRE(std::is_same_v<t2,expected>);
    }
}