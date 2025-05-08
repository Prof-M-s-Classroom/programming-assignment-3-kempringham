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
        MinHeap(5);
    }

private:
    int** adjMatrix;
    int numVertices;
};

#endif