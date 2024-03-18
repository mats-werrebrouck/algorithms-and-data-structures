#include "../catch.hpp"
#include "../../src/search_algorithms/jump_search.cpp"

TEST_CASE("jump search") {
    std::vector<int> arr = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };

    SECTION("target is in the array") {
        REQUIRE(jumpSearch(arr, 55) == 10);
    }

    SECTION("target is not in the array") {
        REQUIRE(jumpSearch(arr, 7) == -1);
    }
}