#include "../catch.hpp"
#include "../../src/search_algorithms/interpolation_search.cpp"

TEST_CASE("Interpolation search") {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    REQUIRE(interpolation_search(arr, 5) == 4);
    REQUIRE(interpolation_search(arr, 10) == 9);
    REQUIRE(interpolation_search(arr, 1) == 0);
    REQUIRE(interpolation_search(arr, 11) == -1);
}