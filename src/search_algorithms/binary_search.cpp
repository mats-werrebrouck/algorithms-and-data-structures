#include <vector>

using namespace std;

// Time complexity: O(log n)
// Space complexity: O(1)
int binary_search(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

// Time complexity:
//  - Best: O(1) (if the target is the middle element)
//  - Average: O(log n)
//  - Worst: O(log n)
// Space complexity: O(1), if the recursive call stack is not considered otherwise O(log n)
int binary_searchv2(const vector<int>& arr, int l, int r, int target) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            return binary_searchv2(arr, l, mid - 1, target);
        }

        return binary_searchv2(arr, mid + 1, r, target);
    }

    return -1;
}