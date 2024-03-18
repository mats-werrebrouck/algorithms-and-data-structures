#include "../catch.hpp"
#include "../../src/search_algorithms/ternary_search.cpp"

TEST_CASE("Ternary search") {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    SECTION("target is in the array") {
        REQUIRE(ternarySearch(arr, 7) == 3);
        REQUIRE(ternarySearchv2(arr, 0, arr.size() - 1, 7) == 3);
    }

    SECTION("target is not in the array") {
        REQUIRE(ternarySearch(arr, 8) == -1);
        REQUIRE(ternarySearchv2(arr, 0, arr.size() - 1, 8) == -1);
    }
}