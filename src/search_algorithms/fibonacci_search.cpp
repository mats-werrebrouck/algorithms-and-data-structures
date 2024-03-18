#include <vector>

using namespace std;

// Time complexity: O(log n)
// Space complexity: O(1)
int fibonacciSearch(const vector<int>& arr, int target) {
    int n = arr.size();

    // Find the smallest fibonacci number that is greater than or equal to the size of the array
    int fibm2 = 0;
    int fibm1 = 1;
    int fibm = fibm1 + fibm2;

    while (fibm < n) {
        fibm2 = fibm1;
        fibm1 = fibm;
        fibm = fibm1 + fibm2;
    }

    // Marks the eliminated range from the front
    int offset = -1;

    // While there are elements to be inspected
    while (fibm > 1) {
        // Check if fibm2 is a valid location
        int current = min(offset + fibm2, n - 1);

        // If the current element is less than the target
        if (arr[current] < target) {
            // cut the subarray from offset to current
            fibm = fibm1;
            fibm1 = fibm2;
            fibm2 = fibm - fibm1;
            offset = current;
        // If the current element is greater than the target
        } else if (arr[current] > target) {
            // cut the subarray after current
            fibm = fibm2;
            fibm1 = fibm1 - fibm2;
            fibm2 = fibm - fibm1;
        } else {
            // Element found
            return current;
        }
    }

    // Compare the last element with the target
    if (fibm1 && arr[offset + 1] == target) {
        return offset + 1;
    }

    // Element not found
    return -1;
}