#include <vector>
#include <algorithm>

using namespace std;

// Time complexity: O(n + m) where n is the number of elements in the input array and m is the range of the count array
// Space complexity: O(n + m)
void countingSort(vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end());

    vector<int> count(max + 1, 0);

    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    vector<int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    std::copy(output.begin(), output.end(), arr.begin());
}