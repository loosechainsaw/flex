#include <flex/meta/rename.hpp>
#include <catch/catch.hpp>
#include <tuple>

TEST_CASE("rename typelist tests") {

    SECTION("empty typelist") {
        using t1 = std::tuple<>;
        using t2 = flex::rename<t1, std::tuple>::type;
        REQUIRE(std::is_same_v<t1,t2>);
    }
    SECTION("single entry typelist") {
        using t1 = std::tuple<int>;
        using t2 = flex::rename<t1, std::tuple>::type;
        using expected = std::tuple<int>;
        REQUIRE(std::is_same_v<t2,expected>);
    }

    SECTION("multiple entry typelist") {
        using t1 = std::tuple<int, double>;
        using t2 = flex::rename<t1, std::pair>::type;
        using expected = std::pair<int, double>;
        REQUIRE(std::is_same_v<t2,expected>);
    }
}