#include "../catch.hpp"
#include "../../src/search_algorithms/ternary_search.cpp"

TEST_CASE("Ternary search") {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    SECTION("target is in the array") {
        REQUIRE(ternary_search(arr, 7) == 3);
        REQUIRE(ternary_searchv2(arr, 0, arr.size() - 1, 7) == 3);
    }

    SECTION("target is not in the array") {
        REQUIRE(ternary_search(arr, 8) == -1);
        REQUIRE(ternary_searchv2(arr, 0, arr.size() - 1, 8) == -1);
    }
}