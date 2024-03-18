#include <vector>
#include <cmath>

using namespace std;

// Time complexity: O(√n)
// Space complexity: O(1)
int jump_search(const vector<int>& arr, int target) {
    int n = arr.size();
    // Determine size of jump
    int jump_size = sqrt(n);

    // Find the block where the target is present
    int prev = 0;
    while (arr[min(jump_size, n) - 1] < target) {
        prev = jump_size;
        jump_size += sqrt(n);

        // We reach end of array
        if (prev >= n) {
            return -1;
        }
    }

    // Linear search in the block
    while (arr[prev] < target) {
        prev++;
       
       // We reach next block or end of array
        if (prev == min(jump_size, n)) {
            return -1;
        }
    }

    // If element is found
    if (arr[prev] == target) {
        return prev;
    }

    return -1;
}