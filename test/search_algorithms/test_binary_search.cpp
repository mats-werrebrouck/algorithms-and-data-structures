#include "../catch.hpp"
#include "../../src/search_algorithms/binary_search.cpp"

TEST_CASE("binary search") {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    SECTION("target is in the array") {
        REQUIRE(binarySearch(arr, 7) == 3);
    }

    SECTION("target is not in the array") {
        REQUIRE(binarySearch(arr, 8) == -1);
    }
}