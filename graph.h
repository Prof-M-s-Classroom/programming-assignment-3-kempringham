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
        adjMatrix[v][u] = weight;
    }

    void primMST() {
        // Must print MST edges and total weight
        // Initialize min heap
        MinHeap(4);
        // Start keys as 0, inf, inf, ....
        // Starts vertices as 0,1,2,3
        // Starts position as 0,1,2,3


        if (size > 2) {
            for (int i = 0; i < numVertices; i++) {
                for (int j = 0; j < numVertices; j++) {
                    if (adjMatrix[i][j] < 0) { // change to less than current key value
                        // decrease key
                    }
                }
            }
        }



    }

private:
    int** adjMatrix;
    int numVertices;
};

#endif