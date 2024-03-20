#include "heap.h"
#include <iostream>

using namespace std;

MinHeap::MinHeap() {}

MinHeap::~MinHeap() {}

void MinHeap::heapify(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap.size() && heap[left] < heap[smallest]) {
        smallest = left;
    }

    if (right < heap.size() && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapify(smallest);
    }
}

void MinHeap::insert(int value) {
    heap.push_back(value);
    int index = heap.size() - 1;

    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

int MinHeap::extractMin() {
    if (heap.empty()) {
        return -1;
    }

    int min = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    heapify(0);

    return min;
}

int MinHeap::getMin() {
    if (heap.empty()) {
        return -1;
    }

    return heap[0];
}

bool MinHeap::isEmpty() {
    return heap.empty();
}


MaxHeap::MaxHeap() {}

MaxHeap::~MaxHeap() {}

void MaxHeap::heapify(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap.size() && heap[left] > heap[largest]) {
        largest = left;
    }

    if (right < heap.size() && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapify(largest);
    }
}

void MaxHeap::insert(int value) {
    heap.push_back(value);
    int index = heap.size() - 1;

    while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

int MaxHeap::extractMax() {
    if (heap.empty()) {
        return -1;
    }

    int max = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    heapify(0);

    return max;
}

int MaxHeap::getMax() {
    if (heap.empty()) {
        return -1;
    }

    return heap[0];
}

bool MaxHeap::isEmpty() {
    return heap.empty();
}

int main() {
    MinHeap minHeap;
    minHeap.insert(3);
    minHeap.insert(2);
    minHeap.insert(1);
    minHeap.insert(15);

    cout << "Min element: " << minHeap.getMin() << endl;
    cout << "Extract min: " << minHeap.extractMin() << endl;
    cout << "Min element after extraction: " << minHeap.getMin() << endl;
    cout << endl;

    MaxHeap maxHeap;
    maxHeap.insert(3);
    maxHeap.insert(2);
    maxHeap.insert(1);
    maxHeap.insert(15);

    cout << "Max element: " << maxHeap.getMax() << endl;
    cout << "Extract max: " << maxHeap.extractMax() << endl;
    cout << "Max element after extraction: " << maxHeap.getMax() << endl;

    return 0;
}