#include "../catch.hpp"
#include "../../src/search_algorithms/fibonacci_search.cpp"

TEST_CASE("fibonacci search") {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    SECTION("target is not in the array") {
        REQUIRE(fibonacci_search(arr, 3) == 1);
    }
    
    SECTION("target is in the array") {
        REQUIRE(fibonacci_search(arr, 19) == 9);
    }

    SECTION("target is not in the array") {
        REQUIRE(fibonacci_search(arr, 8) == -1);
    }
}