#include "../catch.hpp"
#include "../../src/sort_algorithms/heap_sort.cpp"

TEST_CASE("Heap Sort Test") {
    SECTION("Test case 1") {
        vector<int> arr = {12, 11, 13, 5, 6, 7};
        vector<int> expected = {5, 6, 7, 11, 12, 13};
        heapSort(arr);
        REQUIRE(arr == expected);
    }

    SECTION("Test case 2") {
        vector<int> arr = {5, 3, 8, 4, 2};
        vector<int> expected = {2, 3, 4, 5, 8};
        heapSort(arr);
        REQUIRE(arr == expected);
    }
}