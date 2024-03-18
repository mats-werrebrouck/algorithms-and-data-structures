#include <vector>
#include "binary_search.cpp"

using namespace std;

// Time complexity: O(log n)
// Space complexity: O(log n) because of the recursive call stack, if we used iterative binary search then the space complexity would be O(1)
int exponentialSearch(const vector<int>& arr, int target) {
    int n = arr.size();

    if (arr[0] == target) {
        return 0;
    }

    int i = 1;
    while (i < n && arr[i] <= target) {
        i *= 2;
    }

    return binarySearchv2(arr, i / 2, min(i, n - 1), target);
}