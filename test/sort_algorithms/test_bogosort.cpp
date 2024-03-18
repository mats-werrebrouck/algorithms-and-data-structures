#include "../catch.hpp"
#include "../../src/sort_algorithms/bogosort.cpp"

TEST_CASE("isSorted") {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    REQUIRE(isSorted(arr.begin(), arr.end()) == true);
    arr = {5, 2, 3, 1, 4};
    REQUIRE(isSorted(arr.begin(), arr.end()) == false);
}

TEST_CASE("randomShuffle") {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    randomShuffle(arr.begin(), arr.end());
    REQUIRE(arr != std::vector<int>({1, 2, 3, 4, 5}));
}

TEST_CASE("Bogosort") {
    std::vector<int> arr = {5, 2, 3, 1, 4};
    bogoSort(arr);
    REQUIRE(arr == std::vector<int>({1, 2, 3, 4, 5}));
}