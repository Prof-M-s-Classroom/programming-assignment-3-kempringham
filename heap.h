#ifndef HEAP_H
#define HEAP_H
using namespace std;

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
        // use these*
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
    }
    void insert(int vertex, int key) {
        if (size == capacity || isInMinHeap(vertex)) {
            return;
        }

        if (!isInMinHeap(vertex)) {
            heapArray[size] = vertex;
            keyArray[size] = key;
            position[vertex] = size;
            int parent = (size - 1) / 2;
            while (size > 0 && keyArray[size] < keyArray[parent]) {
                swap(heapArray[size], heapArray[parent]);
                swap(keyArray[size], keyArray[parent]);

                position[heapArray[size]] = size;
                position[heapArray[parent]] = parent;

                size = parent;
                parent = (size - 1) / 2;
            }
            // Size is one less than it should be for some reaosn
            size++;
        }
        // If vertex already exists, decrease the key
        //decreaseKey(vertex, key);
    }

    int extractMin() {
        if (size == 0) {
            cout << "Empty MinHeap" << endl;
            return -1;
        }

        int min = heapArray[0];

        heapArray[0] = heapArray[size - 1];
        keyArray[0] = keyArray[size - 1];

        if (size > 1) {
            position[heapArray[0]] = 0;
        }
        position[min] = -1;
        size--;;

        if (size > 0) {
            minHeapify(0);
        }

        return min;
    }

    void decreaseKey(int vertex, int newKey) {
        int index = position[vertex];

        if (index == -1 || newKey < keyArray[index]) {
            return;
        }

        keyArray[index] = newKey;

        int parent = (index - 1) / 2;
        while (index > 0 && keyArray[index] < keyArray[parent]) {
            swap(heapArray[index], heapArray[parent]);
            swap(keyArray[index], keyArray[parent]);

            position[heapArray[index]] = index;
            position[heapArray[parent]] = parent;

            index = parent;
            parent = (index - 1) / 2;
        }


    }

    bool isInMinHeap(int vertex) {
        return position[vertex] != -1 && position[vertex] < size;
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
        int min = idx;
        int left = (2 * idx) + 1;
        int right = (2 * idx) + 2;

        if (left < size && keyArray[left] < keyArray[min]) {
            min = left;
        }

        if (right < size && keyArray[right] < keyArray[min]) {
            min = right;
        }

        if (min != idx) {
            swap(heapArray[idx], heapArray[min]);
            swap(keyArray[idx], keyArray[min]);

            position[heapArray[idx]] = idx;
            position[heapArray[min]] = min;

            minHeapify(min);
        }


    }
};

#endif