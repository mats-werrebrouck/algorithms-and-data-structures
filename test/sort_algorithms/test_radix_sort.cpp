#include "../catch.hpp"
#include "../../src/sort_algorithms/radix_sort.cpp"

TEST_CASE("Testing Radix Sort") {
    SECTION("Least Significant Digit (LSD) Radix Sort") {
        vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
        vector<int> expected = {2, 24, 45, 66, 75, 90, 170, 802};
        lsd_radix_sort(arr);
        REQUIRE(arr == expected);
    }
    
    SECTION("Most Significant Digit (MSD) Radix Sort") {
        vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
        vector<int> expected = {2, 24, 45, 66, 75, 90, 170, 802};
        msd_radix_sort(arr);
        REQUIRE(arr == expected);
    }
}