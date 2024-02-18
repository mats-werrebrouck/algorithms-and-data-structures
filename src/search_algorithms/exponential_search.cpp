#include <vector>
#include "binary_search.cpp"

using namespace std;

int exponential_search(const vector<int>& arr, int target) {
    int n = arr.size();

    if (arr[0] == target) {
        return 0;
    }

    int i = 1;
    while (i < n && arr[i] <= target) {
        i *= 2;
    }

    return binary_searchv2(arr, i / 2, min(i, n - 1), target);
}