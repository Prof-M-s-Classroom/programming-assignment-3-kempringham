#include <iostream>
#include "graph.h"
#include "heap.h"

int main() {

    MinHeap heap(4);
    heap.insert(0, 0);
    heap.insert(1, 2);
    heap.insert(5, 9);
    heap.insert(3, 4);
    heap.extractMin();
    heap.extractMin();
    //heap.extractMin();
    heap.print();

    //int test = heap.extractMin();
    //std::cout << test << std::endl;
    //heap.print();


    /*
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    //g.print();

    g.primMST();
    */
    return 0;
}