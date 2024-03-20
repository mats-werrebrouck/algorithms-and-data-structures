#ifndef HEAP_H
#define HEAP_H

#include <vector>

class MinHeap {
    private:
        std::vector<int> heap;
        void heapify(int index);

    public:
        MinHeap();
        ~MinHeap();

        void insert(int data);
        void remove(int data);
        int extractMin();
        int getMin();
        bool isEmpty();
};

class MaxHeap {
    private:
        std::vector<int> heap;
        void heapify(int index);
    
    public:
        MaxHeap();
        ~MaxHeap();

        void insert(int data);
        void remove(int data);
        int extractMax();
        int getMax();
        bool isEmpty();
};

#endif