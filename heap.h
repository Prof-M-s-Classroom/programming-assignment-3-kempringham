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
        if (size >= capacity) {
            return; // Fix for edge case
        }

        if (!isInMinHeap(vertex)) {
            int index = size;
            heapArray[size] = vertex;
            keyArray[size] = key;
            position[size] = index;
            minHeapify(index);
            size++;
        }

    }


    int extractMin() {
        if (size == 0) {
            return 0;
        }
        int min = heapArray[0];
        position[] = 0;
        decreaseKey(index, keyArray[index]); // if adj matrix is not inf, it is a neighbor
        size--;
        return min;
    }

    void decreaseKey(int vertex, int newKey) {
        keyArray[position[vertex]] = newKey;
        minHeapify(position[vertex]);
    }

    bool isInMinHeap(int vertex) {
        for (int i = 0; i < size; i++) {
            if (heapArray[i] == vertex) {
                return true;
            }
        }
        return false;
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
        if (size == 0) {
            return;
        }
        for (int i = idx - 1; i >= 0; i++) {
            if (keyArray[idx] < keyArray[i]) {
                int tempkey = keyArray[i];
                int temp_position = position[i];
                int tempvertex = heapArray[i];
                heapArray[i] = heapArray[idx];
                keyArray[i] = keyArray[idx];
                position[i] = position[idx];
                heapArray[idx] = tempvertex;
                keyArray[tempvertex] = tempkey;
                position[tempvertex] = temp_position;
            }
        }
    }

};

#endif