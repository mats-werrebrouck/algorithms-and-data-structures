#include "../catch.hpp"
#include "../../src/search_algorithms/exponential_search.cpp"

TEST_CASE("Exponential Search") {
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> arr4 = {1, 2, 3, 4, 5, 6};
    vector<int> arr5 = {1, 2, 3, 4, 5};
    vector<int> arr6 = {1, 2, 3, 4};
    vector<int> arr7 = {1, 2, 3};
    vector<int> arr8 = {1, 2};
    vector<int> arr9 = {1};

    SECTION("Array with one element") {
        REQUIRE(exponentialSearch(arr9, 1) == 0);
        REQUIRE(exponentialSearch(arr9, 2) == -1);
    }

    SECTION("Array with two elements") {
        REQUIRE(exponentialSearch(arr8, 1) == 0);
        REQUIRE(exponentialSearch(arr8, 2) == 1);
        REQUIRE(exponentialSearch(arr8, 3) == -1);
    }

    SECTION("Array with three elements") {
        REQUIRE(exponentialSearch(arr7, 1) == 0);
        REQUIRE(exponentialSearch(arr7, 2) == 1);
        REQUIRE(exponentialSearch(arr7, 3) == 2);
        REQUIRE(exponentialSearch(arr7, 4) == -1);
    }

    SECTION("Array with four elements") {
        REQUIRE(exponentialSearch(arr6, 1) == 0);
        REQUIRE(exponentialSearch(arr6, 2) == 1);
        REQUIRE(exponentialSearch(arr6, 3) == 2);
        REQUIRE(exponentialSearch(arr6, 4) == 3);
        REQUIRE(exponentialSearch(arr6, 5) == -1);
    }

    SECTION("Array with five elements") {
        REQUIRE(exponentialSearch(arr5, 1) == 0);
        REQUIRE(exponentialSearch(arr5, 2) == 1);
        REQUIRE(exponentialSearch(arr5, 3) == 2);
        REQUIRE(exponentialSearch(arr5, 4) == 3);
        REQUIRE(exponentialSearch(arr5, 5) == 4);
        REQUIRE(exponentialSearch(arr5, 6) == -1);
    }

    SECTION("Array with six elements") {
        REQUIRE(exponentialSearch(arr4, 1) == 0);
        REQUIRE(exponentialSearch(arr4, 2) == 1);
        REQUIRE(exponentialSearch(arr4, 3) == 2);
        REQUIRE(exponentialSearch(arr4, 4) == 3);
        REQUIRE(exponentialSearch(arr4, 5) == 4);
        REQUIRE(exponentialSearch(arr4, 6) == 5);
        REQUIRE(exponentialSearch(arr4, 7) == -1);
    }

    SECTION("Array with seven elements") {
        REQUIRE(exponentialSearch(arr3, 1) == 0);
        REQUIRE(exponentialSearch(arr3, 2) == 1);
        REQUIRE(exponentialSearch(arr3, 3) == 2);
        REQUIRE(exponentialSearch(arr3, 4) == 3);
        REQUIRE(exponentialSearch(arr3, 5) == 4);
        REQUIRE(exponentialSearch(arr3, 6) == 5);
        REQUIRE(exponentialSearch(arr3, 7) == 6);
        REQUIRE(exponentialSearch(arr3, 8) == -1);
    }

    SECTION("Array with eight elements") {
        REQUIRE(exponentialSearch(arr2, 1) == 0);
        REQUIRE(exponentialSearch(arr2, 2) == 1);
        REQUIRE(exponentialSearch(arr2, 3) == 2);
        REQUIRE(exponentialSearch(arr2, 4) == 3);
        REQUIRE(exponentialSearch(arr2, 5) == 4);
        REQUIRE(exponentialSearch(arr2, 6) == 5);
        REQUIRE(exponentialSearch(arr2, 7) == 6);
        REQUIRE(exponentialSearch(arr2, 8) == 7);
        REQUIRE(exponentialSearch(arr2, 9) == -1);
    }

    SECTION("Array with nine elements") {
        REQUIRE(exponentialSearch(arr1, 1) == 0);
        REQUIRE(exponentialSearch(arr1, 2) == 1);
        REQUIRE(exponentialSearch(arr1, 3) == 2);
        REQUIRE(exponentialSearch(arr1, 4) == 3);
        REQUIRE(exponentialSearch(arr1, 5) == 4);
        REQUIRE(exponentialSearch(arr1, 6) == 5);
        REQUIRE(exponentialSearch(arr1, 7) == 6);
        REQUIRE(exponentialSearch(arr1, 8) == 7);
        REQUIRE(exponentialSearch(arr1, 9) == 8);
        REQUIRE(exponentialSearch(arr1, 10) == -1);
    }
}