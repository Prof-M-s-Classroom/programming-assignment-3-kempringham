#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        size = 0;

        heapArray = new int[capacity];
        keyArray = new int[capacity];
        position = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            heapArray[i] = INT_MAX;
            keyArray[i] = INT_MAX;
            position[i] = -1;
        }
    }

    ~MinHeap() {
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
    }
    void insert(int vertex, int key) {
        if (size == capacity) {
            return;
        }

        if (!isInMinHeap(vertex)) {
            heapArray[size] = vertex;
            keyArray[size] = key;
            position[size] = size;
            minHeapify(size);
            // Size is one less than it should be for some reaosn
            size++;
        }
        // If vertex already exists, decrease the key
        //decreaseKey(vertex, key);
    }

    int extractMin() {
        if (size == 0) {
            std::cout << "Empty MinHeap" << std::endl;
            return -1;
        }

        int min = heapArray[0];
        position[0] = 0;

        for (int i = 0; i <= size; i++) {
            heapArray[i] = heapArray[i+1];
        }

        // Fix for loop(size is one less than it should be)
        for (int i = 0; i <= size + 1; i++) {
            if (position[i] != 0) {
                position[i] -= 1;
            }

        }
        heapArray[size] = heapArray[size-1];
        size--;
        return min;
    }

    void decreaseKey(int vertex, int newKey) {
        keyArray[position[vertex]] = newKey;
    }

    void print() {
        for (int i = 0; i < capacity; i++) {
            std::cout << heapArray[i] << " ";
        }

        std::cout << std::endl;
        for (int j = 0; j < capacity; j++) {
            std::cout << keyArray[j] << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < capacity; i++) {
            std::cout << position[i] << " ";
        }
    }

    bool isInMinHeap(int vertex) {
        for(int i = 0; i < size; i++) {
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
        if (idx > 0 && idx <= size && size > 0) {
            for (int i = idx - 1; i >= 0; i--) {
                if (heapArray[idx] < heapArray[i]) {
                    swap(heapArray[idx], heapArray[i]);
                    swap(keyArray[idx], keyArray[i]);
                    idx--;
                }
            }
        }
    }
};

#endif