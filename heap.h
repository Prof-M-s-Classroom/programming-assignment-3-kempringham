#ifndef HEAP_H
#define HEAP_H
using namespace std; // Added for swap and print(cout)

class MinHeap {
public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        size = 0;
        // Store vertices
        heapArray = new int[capacity];
        // Store key values of vertices
        keyArray = new int[capacity];
        // Store position of vertices in min heap
        position = new int[capacity];
        // Initialize vertices and key values to infinity and position to -1
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
        // If the min heap is already full or the vertex is in the heap, you cannot insert it
        if (size == capacity || isInMinHeap(vertex)) {
            return;
        }
        // Insert vertex and key into the end of the heap
        heapArray[size] = vertex;
        keyArray[size] = key;
        position[vertex] = size;

        // If the key value is lower than parent, keep moving it up heap until minheap property is satisfied
        int parent = (size - 1) / 2;
        while (size > 0 && keyArray[size] < keyArray[parent]) {
            swap(heapArray[size], heapArray[parent]);
            swap(keyArray[size], keyArray[parent]);

            position[heapArray[size]] = size;
            position[heapArray[parent]] = parent;

            size = parent;
            parent = (size - 1) / 2;
        }

        // After you insert, the size needs to be incremented because it has one more vertex in the heap
        size++;
    }

    int extractMin() {
        // Min cannot be extract if the heap is empty
        if (size == 0) {
            cout << "Empty MinHeap" << endl;
            return -1;
        }

        // Root of heap
        int min = heapArray[0];

        // Bottom of heap should now become the new root
        heapArray[0] = heapArray[size - 1];
        keyArray[0] = keyArray[size - 1];

        if (size > 1) {
            position[heapArray[0]] = 0;
        }

        // The extracted min should no longer be in the heap
        position[min] = -1;
        // Decrement because a vertex was removed
        size--;;

        // Restore heap property
        if (size > 0) {
            minHeapify(0);
        }

        return min;
    }

    void decreaseKey(int vertex, int newKey) {
        if (position[vertex] == -1 || keyArray[position[vertex]] <= newKey) {
            return;
        }

        // Update the key
        keyArray[position[vertex]] = newKey;

        // New key would result in "smaller" value, will need to upheap into correct spot
        int curr = position[vertex];
        int parent = (curr - 1) / 2;
        while (curr > 0 && keyArray[curr] < keyArray[parent]) {
            // Swap the nodes
            std::swap(heapArray[curr], heapArray[parent]);
            std::swap(keyArray[curr], keyArray[parent]);

            // Update position array
            position[heapArray[curr]] = curr;
            position[heapArray[parent]] = parent;

            // Move up
            curr = parent;
            parent = (curr - 1) / 2;
        }
    }

    bool isInMinHeap(int vertex) {
        // If position is -1, it was removed from min heap
        // If position > size, it is in the heap
        return position[vertex] != -1 && position[vertex] < size;
    }

    bool isEmpty() {
        // If size is 0, there is nothing in the heap
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
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        // Find the smallest key value between parent, left child, and right child
        if (left < size && keyArray[left] < keyArray[min])
            min = left;

        if (right < size && keyArray[right] < keyArray[min])
            min = right;

        // If smallest key is not at the top, swap so that it moves up
        if (min != idx) {
            swap(heapArray[idx], heapArray[min]);
            swap(keyArray[idx], keyArray[min]);

            position[heapArray[idx]] = idx;
            position[heapArray[min]] = min;

            minHeapify(min); // Repeat until min heap property is restored
        }
    }

};

#endif