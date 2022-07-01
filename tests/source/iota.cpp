#include <flex/meta/iota.hpp>
#include <catch/catch.hpp>
#include <tuple>

TEST_CASE("iota typelist tests") {

    SECTION("empty typelist") {
        using t1 = std::tuple<>;
        using t2 = flex::iota<t1, 3UL>::type;
        using expected = std::tuple<std::integral_constant<size_t, 0>, std::integral_constant<size_t, 1>, std::integral_constant<size_t, 2>>;
        REQUIRE(std::is_same_v<t2, expected>);
    }

    SECTION("empty entry requesting 0") {
        using t1 = std::tuple<>;
        using t2 = flex::iota<t1, 0>::type;
        using expected = std::tuple<>;
        REQUIRE(std::is_same_v<t2,expected>);
    }

}