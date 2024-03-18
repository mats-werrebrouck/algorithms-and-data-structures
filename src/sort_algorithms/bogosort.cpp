#include <vector>
#include <cstdlib>
#include <ctime> 

using namespace std;

bool isSorted(vector<int>::iterator begin, vector<int>::iterator end) {
    for (auto it = begin; it != end - 1; it++) {
        if (*it > *(it + 1)) {
            return false;
        }
    }
    return true;
}

void randomShuffle(vector<int>::iterator begin, vector<int>::iterator end) {
    srand(time(nullptr));

    for (auto it = begin; it != end; it++) {
        iter_swap(it, begin + rand() % (end - begin));
    }
}

// Time complexity: 
// Worst case: O(infinity)
// Average case: O(n * n!)
// Best case: O(n)
// Space complexity: O(1)
void bogoSort(vector<int>& arr) {
    while (!isSorted(arr.begin(), arr.end())) {
        randomShuffle(arr.begin(), arr.end());
    }
}