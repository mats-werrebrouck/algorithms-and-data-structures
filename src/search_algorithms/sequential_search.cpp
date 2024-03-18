#include <vector>

using namespace std;

// Time complexity:
//  - Best: O(1) (if the target is the first element)
//  - Average: O(n)
//  - Worst: O(n) (if the target is the last element)
int sequentialSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}