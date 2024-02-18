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
        REQUIRE(exponential_search(arr9, 1) == 0);
        REQUIRE(exponential_search(arr9, 2) == -1);
    }

    SECTION("Array with two elements") {
        REQUIRE(exponential_search(arr8, 1) == 0);
        REQUIRE(exponential_search(arr8, 2) == 1);
        REQUIRE(exponential_search(arr8, 3) == -1);
    }

    SECTION("Array with three elements") {
        REQUIRE(exponential_search(arr7, 1) == 0);
        REQUIRE(exponential_search(arr7, 2) == 1);
        REQUIRE(exponential_search(arr7, 3) == 2);
        REQUIRE(exponential_search(arr7, 4) == -1);
    }

    SECTION("Array with four elements") {
        REQUIRE(exponential_search(arr6, 1) == 0);
        REQUIRE(exponential_search(arr6, 2) == 1);
        REQUIRE(exponential_search(arr6, 3) == 2);
        REQUIRE(exponential_search(arr6, 4) == 3);
        REQUIRE(exponential_search(arr6, 5) == -1);
    }

    SECTION("Array with five elements") {
        REQUIRE(exponential_search(arr5, 1) == 0);
        REQUIRE(exponential_search(arr5, 2) == 1);
        REQUIRE(exponential_search(arr5, 3) == 2);
        REQUIRE(exponential_search(arr5, 4) == 3);
        REQUIRE(exponential_search(arr5, 5) == 4);
        REQUIRE(exponential_search(arr5, 6) == -1);
    }

    SECTION("Array with six elements") {
        REQUIRE(exponential_search(arr4, 1) == 0);
        REQUIRE(exponential_search(arr4, 2) == 1);
        REQUIRE(exponential_search(arr4, 3) == 2);
        REQUIRE(exponential_search(arr4, 4) == 3);
        REQUIRE(exponential_search(arr4, 5) == 4);
        REQUIRE(exponential_search(arr4, 6) == 5);
        REQUIRE(exponential_search(arr4, 7) == -1);
    }

    SECTION("Array with seven elements") {
        REQUIRE(exponential_search(arr3, 1) == 0);
        REQUIRE(exponential_search(arr3, 2) == 1);
        REQUIRE(exponential_search(arr3, 3) == 2);
        REQUIRE(exponential_search(arr3, 4) == 3);
        REQUIRE(exponential_search(arr3, 5) == 4);
        REQUIRE(exponential_search(arr3, 6) == 5);
        REQUIRE(exponential_search(arr3, 7) == 6);
        REQUIRE(exponential_search(arr3, 8) == -1);
    }

    SECTION("Array with eight elements") {
        REQUIRE(exponential_search(arr2, 1) == 0);
        REQUIRE(exponential_search(arr2, 2) == 1);
        REQUIRE(exponential_search(arr2, 3) == 2);
        REQUIRE(exponential_search(arr2, 4) == 3);
        REQUIRE(exponential_search(arr2, 5) == 4);
        REQUIRE(exponential_search(arr2, 6) == 5);
        REQUIRE(exponential_search(arr2, 7) == 6);
        REQUIRE(exponential_search(arr2, 8) == 7);
        REQUIRE(exponential_search(arr2, 9) == -1);
    }

    SECTION("Array with nine elements") {
        REQUIRE(exponential_search(arr1, 1) == 0);
        REQUIRE(exponential_search(arr1, 2) == 1);
        REQUIRE(exponential_search(arr1, 3) == 2);
        REQUIRE(exponential_search(arr1, 4) == 3);
        REQUIRE(exponential_search(arr1, 5) == 4);
        REQUIRE(exponential_search(arr1, 6) == 5);
        REQUIRE(exponential_search(arr1, 7) == 6);
        REQUIRE(exponential_search(arr1, 8) == 7);
        REQUIRE(exponential_search(arr1, 9) == 8);
        REQUIRE(exponential_search(arr1, 10) == -1);
    }
}