#include <vector>

using namespace std;

// Time complexity: O(n^2), but best case is O(n) when the array is already sorted
// Space complexity: O(1)
void insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
            j--;
        }
    }
}