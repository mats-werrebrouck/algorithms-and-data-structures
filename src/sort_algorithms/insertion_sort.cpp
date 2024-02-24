#include <vector>

using namespace std;

void insertion_sort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
            j--;
        }
    }
}