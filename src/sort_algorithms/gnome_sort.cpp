#include <vector>

using namespace std;

// Time complexity: O(n^2)
// Space complexity: O(1)
void gnomeSort(vector<int>& arr) {
    int n = arr.size();
    int index = 0;
    while (index < n) {
        if (index == 0) {
            index++;
        }
        if (arr[index] >= arr[index - 1]) {
            index++;
        } else {
            swap(arr[index], arr[index - 1]);
            index--;
        }
    }
}