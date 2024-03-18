#include <vector>

using namespace std;

// Function to find the median of three elements in the array
int medianOfThree(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid]) {
        swap(arr[low], arr[mid]);
    }
    if (arr[mid] > arr[high]) {
        swap(arr[mid], arr[high]);
    }
    if (arr[low] > arr[mid]) {
        swap(arr[low], arr[mid]);
    }
    return mid;
}

int partiton(vector<int>& arr, int low, int high) {
    // Choose the pivot as the last element
    int pivot = arr[high];

    int i = low;
    int j = high - 1;
   
    while (i <= j) {
        // Find element greater than pivot from the left side
        while (i <= j && arr[i] < pivot) {
            i++;
        }

        // Find element smaller than pivot from the right side
        while (i <= j && arr[j] > pivot) {
            j--;
        }

        // Swap elements if inverse found
        if (i < j) {
            swap(arr[i++], arr[j--]);
        }
    }

    swap(arr[i], arr[high]);
    return i;

    // int i = low - 1;
   
    // for(int j = low; j <= high; j++) {
    //     //If current element is smaller than the pivot
    //     if(arr[j] < pivot) {
    //         //Increment index of smaller element
    //         i++;
    //         swap(arr[i],arr[j]);
    //     }
    // }

    // swap(arr[i+1],arr[high]);
    // return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIdx = medianOfThree(arr, low, high);
        // Move the pivot to the end of the array
        swap(arr[pivotIdx], arr[high]);
        // Partition the array and get the index of the pivot
        int partitionIdx = partiton(arr, low, high);
        // Recursively sort the left and right halves of the array
        quickSort(arr, low, partitionIdx - 1);
        quickSort(arr, partitionIdx + 1, high);
    }
}

// Time complexity: O(n log n)
// Space complexity: O(log n)

// Wrapper function to call quickSort with the correct parameters
void quickSort(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}