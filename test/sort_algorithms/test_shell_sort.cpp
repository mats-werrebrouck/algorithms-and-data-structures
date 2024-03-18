#include "../catch.hpp"
#include "../../src/sort_algorithms/shell_sort.cpp"

TEST_CASE("Testing Shell Sort") {
    SECTION("Shell Sort") {
        vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
        vector<int> expected = {2, 24, 45, 66, 75, 90, 170, 802};
        shellSort(arr);
        REQUIRE(arr == expected);
    }

    SECTION("Shell Sort with negative numbers") {
        vector<int> arr = {170, -45, 75, 90, -802, 24, 2, 66};
        vector<int> expected = {-802, -45, 2, 24, 66, 75, 90, 170};
        shellSort(arr);
        REQUIRE(arr == expected);
    }

    SECTION("Shell Sort with sedgeick's increments") {
        vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
        vector<int> expected = {2, 24, 45, 66, 75, 90, 170, 802};
        shellSortSedgewick(arr);
        REQUIRE(arr == expected);
    }
}