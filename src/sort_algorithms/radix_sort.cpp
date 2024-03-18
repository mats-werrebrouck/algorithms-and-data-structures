#include <vector>
#include <algorithm>

using namespace std;

void counting_sort(vector<int>& arr, int exp) {
    int max = *max_element(arr.begin(), arr.end());

    vector<int> count(max + 1, 0);
    vector<int> output(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        count[(arr[i] / exp)]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp)] - 1] = arr[i];
        count[(arr[i] / exp)]--;
    }

    std::copy(output.begin(), output.end(), arr.begin());
}

// Time complexity: O(d * (n + k)) where d is the number of digits in the largest number, n is the number of elements in the input array and k is the base of the number system
// Space complexity: O(n + k)
void lsd_radix_sort(vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end());

    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort(arr, exp);
    }
}

// Time complexity: O(n log(base m) n) where n is the number of elements in the input array and m is the base of the number system
// Space complexity: O(n + m)
void msd_radix_sort(vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end());

    int digits = 1;
    while (digits < max) {
        digits *= 10;
    }

    for (; digits > 0; digits /= 10) {
        counting_sort(arr, digits);
    }
}