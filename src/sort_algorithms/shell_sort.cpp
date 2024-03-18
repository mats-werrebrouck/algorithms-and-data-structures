#include <vector>

using namespace std;

// Time complexity: 
// Best case: O(n log n)
// Worst case: O(n^2)
// Space complexity: O(1)
void shellSort(vector<int>& arr) {
    int n = arr.size();

    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        for (int i = gap; i < n; i++) {
            // Store arr[i] in temp and make a hole at position i
            int temp = arr[i];
            int j;
            // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            // Put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

void shellSortSedgewick(vector<int>& arr) {
    int n = arr.size();

    // Sedgewick's increments
    vector<long long> sedgewick;
    int k = 0;

    while (true) {
        if (k % 2 == 0) {
            // 9 * (2^k - 2^(k/2)) + 1
            sedgewick.push_back(9 * (1 << k) - 9 * (1 << (k / 2)) + 1);
        } else {
            // 8 * (2^k - 2^((k+1)/2)) + 1
            sedgewick.push_back(8 * (1 << k) - 6 * (1 << ((k + 1) / 2)) + 1);
        }

        // If the increment is greater than n, stop
        if (sedgewick.back() >= n) {
            break;
        }

        k++;
    }
    
    for (int i = sedgewick.size() - 1; i >= 0; i--) {
        int gap = sedgewick[i];
        for (int j = gap; j < n; j++) {
            int temp = arr[j];
            int k;
            for (k = j; k >= gap && arr[k - gap] > temp; k -= gap) {
                arr[k] = arr[k - gap];
            }
            arr[k] = temp;
        }
    }
}