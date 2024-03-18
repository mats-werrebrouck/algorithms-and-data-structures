#include "../catch.hpp"
#include "../../src/sort_algorithms/bucket_sort.cpp"

TEST_CASE("Testing Bucket Sort") {
    SECTION("Bucket Sort") {
        vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
        vector<int> expected = {2, 24, 45, 66, 75, 90, 170, 802};
        bucket_sort(arr);
        REQUIRE(arr == expected);
    }

    SECTION("Bucket Sort with negative numbers") {
        vector<int> arr = {170, -45, 75, 90, -802, 24, 2, 66};
        vector<int> expected = {-802, -45, 2, 24, 66, 75, 90, 170};
        bucket_sort(arr);
        REQUIRE(arr == expected);
    }
}