#include <vector>

using namespace std;

void selection_sort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            swap(arr[i], arr[min_index]);
        }
    }
}