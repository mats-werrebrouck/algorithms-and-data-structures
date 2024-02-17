#include "../catch.hpp"
#include "../../src/sort_algorithms/bogosort.cpp"

TEST_CASE("is_sorted") {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    REQUIRE(is_sorted(arr.begin(), arr.end()) == true);
    arr = {5, 2, 3, 1, 4};
    REQUIRE(is_sorted(arr.begin(), arr.end()) == false);
}

TEST_CASE("random_shuffle") {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    random_shuffle(arr.begin(), arr.end());
    REQUIRE(arr != std::vector<int>({1, 2, 3, 4, 5}));
}

TEST_CASE("Bogosort") {
    std::vector<int> arr = {5, 2, 3, 1, 4};
    bogo_sort(arr);
    REQUIRE(arr == std::vector<int>({1, 2, 3, 4, 5}));
}