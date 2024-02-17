#include <vector>
#include <cstdlib>
#include <ctime>  

bool is_sorted(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    for (auto it = begin; it != end - 1; it++) {
        if (*it > *(it + 1)) {
            return false;
        }
    }
    return true;
}

void random_shuffle(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    srand(time(nullptr));

    for (auto it = begin; it != end; it++) {
        std::iter_swap(it, begin + rand() % (end - begin));
    }
}

void bogo_sort(std::vector<int>& arr) {
    while (!is_sorted(arr.begin(), arr.end())) {
        random_shuffle(arr.begin(), arr.end());
    }
}