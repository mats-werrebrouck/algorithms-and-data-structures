#include <vector>

using namespace std;
// Time complexity: O(log log n) on average and O(n) in worst case
// Space complexity: O(1)

// Improvment over binary search where the values in a sorted array are uniformly distributed
int interpolation_search(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    // Since array is sorted, an element present in array must be in range defined by the boundaries
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // If there is only one element in the array
        if (low == high) {
            if (arr[low] == target) {
                return low;
            }
            return -1;
        }

        // calculate the position using interpolation formula
        // Equation of a line: y = mx + c, y is the value and x is the index
        // Now, we can write the above equation as:
        // arr[high] = m*high + c
        // arr[low] = m*low + c     (1)
        // y = m*pos + c    (2)
        // m = (arr[high] - arr[low]) / (high - low)
        // Substracting (1) from (2) we get:
        // y - arr[low] = m * (pos - low)
        // pos = low + (y - arr[low]) / m
        // pos = low + ((y - arr[low]) * (high - low)) / (arr[high] - arr[low])
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target) {
            return pos;
        }

        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;
}