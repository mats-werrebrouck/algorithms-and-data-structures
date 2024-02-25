#include <vector>

using namespace std;

void gnome_sort(vector<int>& arr) {
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