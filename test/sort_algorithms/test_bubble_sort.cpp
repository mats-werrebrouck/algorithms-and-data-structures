#include "../catch.hpp"
#include "../../src/sort_algorithms/bubble_sort.cpp"

TEST_CASE("Bubble Sort") {
    std::vector<int> arr = {5, 2, 3, 1, 4};
    bubbleSort(arr);
    REQUIRE(arr == std::vector<int>({1, 2, 3, 4, 5}));
}