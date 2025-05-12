#ifndef GRAPH_H
#define GRAPH_H
using namespace std; // added
#include "heap.h"

class Graph {
public:
    int inf = INT_MAX;
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = inf;
            }
        }

    }

    ~Graph() {
        delete adjMatrix;
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        // directed or undirected?
        //adjMatrix[v][u] = weight;
    }

    void primMST() {
        // Must print MST edges and total weight
        // Initialize min heap
        MinHeap heap(numVertices);

        // Start keys as 0, inf, inf, ....
        // Starts vertices as 0,1,2,3,...
        // Starts position as 0,1,2,3,...

        // Insert vertex 0 into heap
        heap.insert(0,0);

        // Initialize the rest of the values of the heap
        for (int i = 0; i < numVertices; i++) {
            heap.insert(i, INT_MAX);
        }

        // Initialize key values for first row
        for (int i = 0; i < numVertices; i++) {
            heap.decreaseKey(i, adjMatrix[0][i]);
        }


        // Updates arrays (extract min and decrease key)
        for (int i = 1; i < numVertices + 1; i++) {
            heap.extractMin();
            for (int j = i+1; j < numVertices; j++) {
                if (adjMatrix[i][j] < adjMatrix[i - 1][j]) {
                     heap.decreaseKey(j, adjMatrix[i][j]);
                }
            }
        }

        heap.decreaseKey(0,0);


        heap.print();



    }


private:
    int** adjMatrix;
    int numVertices;
};

#endif