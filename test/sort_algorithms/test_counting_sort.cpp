#include "../catch.hpp"
#include "../../src/sort_algorithms/counting_sort.cpp"

TEST_CASE("Counting Sort") {
    SECTION("Sorting positive integers") {
        vector<int> arr = {4, 2, 1, 3, 2, 4, 1};
        vector<int> expected = {1, 1, 2, 2, 3, 4, 4};

        counting_sort(arr);

        REQUIRE(arr == expected);
    }
}