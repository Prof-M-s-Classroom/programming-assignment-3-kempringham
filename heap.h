#ifndef HEAP_H
#define HEAP_H
#include <algorithm>
#include <__algorithm/ranges_min.h>
#include <__filesystem/path.h>
using namespace std; // Use swap in C++

class MinHeap {
public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        size = 0;
        heapArray = new int[capacity];
        keyArray = new int[capacity];
        position = new int[capacity];
    }

    ~MinHeap() {
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
    }

    void insert(int vertex, int key) {
        // Check that capacity has not been reached
        if (size >= capacity) {
            return;
        }

        int index = size;
        heapArray[index] = vertex;
        keyArray[vertex] = key;
        position[vertex] = index;
        size++;

        while (index != 0 && keyArray[heapArray[index]] < keyArray[heapArray[(index - 1) / 2]]) {
            int parentIndex = (index - 1) / 2;

            position[heapArray[index]] = parentIndex;
            position[heapArray[parentIndex]] = index;

            std::swap(heapArray[index], heapArray[parentIndex]);
            std::swap(keyArray[heapArray[index]], keyArray[heapArray[parentIndex]]);

            index = parentIndex;
        }
    }


    int extractMin() {
        // Check edge case
        if (size == 0) {
            return -1;
        }

        // Minimum value is stored at top
        int min = heapArray[0];

        // If there is only one element
        if (size == 1) {
            size--;
            return min;
        }

        heapArray[0] = heapArray[size - 1];
        keyArray[0] = keyArray[size - 1];
        position[heapArray[0]] = 0;
        size--;
        minHeapify(0); // Min index is always 0

        return min;

    }

    void decreaseKey(int vertex, int newKey) {
        if (size == 0) {
            return;
        }
        int index = position[vertex];
        // Update key
        keyArray[index] = newKey;

        while (index > 0 && keyArray[index] < keyArray[(index - 1) / 2]) {
            int parentIndex = (index - 1) / 2;
            swap(heapArray[index], heapArray[parentIndex]);
            swap(position[heapArray[index]], position[heapArray[parentIndex]]);
            index = parentIndex;
        }
    }

    bool isInMinHeap(int vertex) {
        return (position[vertex] >= 0 && position[vertex] < size);
    }

    bool isEmpty() {
        return size == 0;
    }

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    void minHeapify(int idx) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < size && keyArray[left] < keyArray[smallest]) {
            smallest = left;
        }

        if (right < size && keyArray[right] < keyArray[smallest]) {
            smallest = right;
        }

        if (smallest != idx) {
            swap(heapArray[smallest], heapArray[idx]);
            swap(position[heapArray[smallest]], position[heapArray[idx]]);
            minHeapify(smallest);
        }


    }
};

#endif