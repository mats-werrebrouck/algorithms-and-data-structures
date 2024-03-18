#include <vector>

using namespace std;

// Time complexity: O(n log n)
// Space complexity: O(n)
void mergeSort(vector<int>& arr) {
    // Base case when the array has 0 or 1 elements, it is already sorted
    if (arr.size() <= 1) return;

    // Split the array into two halves
    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    // Recursively divide the left and right halves until the base case is reached
    mergeSort(left);
    mergeSort(right);

    // Once the base case is reached, merge the left and right halves in sorted order
    int i = 0, j = 0, k = 0;
    // Iterate through the left and right halves, comparing elements and adding the smaller one to the original array
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // Add any remaining elements from the left and right halves to the original array
    while (i < left.size()) {
        arr[k++] = left[i++];
    }

    while (j < right.size()) {
        arr[k++] = right[j++];
    }
}