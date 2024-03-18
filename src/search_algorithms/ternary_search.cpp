#include <vector>

using namespace std;

// Time complexity: O(2 log(base 3) n)
// Space complexity: O(1)
int ternarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target) {
            return mid1;
        }

        if (arr[mid2] == target) {
            return mid2;
        }

        if (arr[mid1] > target) {
            right = mid1 - 1;
        } else if (arr[mid2] < target) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }

    return -1;
}

// Time complexity: O(2 log(base 3) n)
// Space complexity: O(log(base 3) n) because of the recursive call stack
int ternarySearchv2(const vector<int>& arr, int l, int r, int target) {
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (arr[mid1] == target) {
            return mid1;
        }

        if (arr[mid2] == target) {
            return mid2;
        }

        if (arr[mid1] > target) {
            return ternarySearchv2(arr, l, mid1 - 1, target);
        }

        if (arr[mid2] < target) {
            return ternarySearchv2(arr, mid2 + 1, r, target);
        }

        return ternarySearchv2(arr, mid1 + 1, mid2 - 1, target);
    }

    return -1;
}