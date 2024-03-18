#include <vector>
#include <algorithm>

using namespace std;

// Time complexity: O(n^2)
// Space complexity: O(n + k), where k is the number of buckets
void bucketSort(vector<int>& arr) {
    int n = arr.size();

    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());

    int bucket_size = 5;
    int bucket_count = (max_val - min_val) / bucket_size + 1;

    // Create buckets
    vector<vector<int>> buckets(bucket_count);

    // Add elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (arr[i] - min_val) / bucket_size;
        buckets[index].push_back(arr[i]);
    }

    // Sort elements in each bucket
    for (int i = 0; i < bucket_count; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Merge buckets
    int index = 0;
    for (int i = 0; i < bucket_count; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}