#include "../catch.hpp"
#include "../../src/sort_algorithms/gnome_sort.cpp"


TEST_CASE("Gnome Sort") {

    SECTION("Test case 1") {
        vector<int> arr = {5, 2, 4, 6, 1, 3};
        vector<int> expected = {1, 2, 3, 4, 5, 6};
        gnome_sort(arr);
        REQUIRE(arr == expected);
    }

    SECTION("Test case 2") {
        vector<int> arr = {31, 41, 59, 26, 41, 58};
        vector<int> expected = {26, 31, 41, 41, 58, 59};
        gnome_sort(arr);
        REQUIRE(arr == expected);
    }
}