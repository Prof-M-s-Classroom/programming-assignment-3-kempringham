#ifndef GRAPH_H
#define GRAPH_H
using namespace std; // added for print(cout)
#include "heap.h"

class Graph {
public:
    // Create variable for infinity, which is needed when there's no edge connecting 2 vertices
    int inf = INT_MAX;

    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                // There's no edges between vertices orignally
                adjMatrix[i][j] = inf;
            }
        }
    }

    ~Graph() {
        // Destructor to avoid memory leak
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    void addEdge(int u, int v, int weight) {
        // MST must be undirected
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }
    void primMST() {
        // Stores the starting vertices
        int* parent = new int[numVertices];

        // Stores the current lowest weights
        int* key = new int[numVertices];

        MinHeap heap(numVertices);

        for (int i = 0; i < numVertices; i++) {
            // All the keys should originally be infinity, so they can be decreased when edges are chosen
            key[i] = INT_MAX;
            // We don't know the parents yet so set to -1
            parent[i] = -1;
        }

        // Our arbitrary starting vertex is 0
        key[0] = 0;

        // Insert all vertices into the min heap
        for (int v = 0; v < numVertices; v++) {
            heap.insert(v, key[v]);
        }

        int totalWeight = 0;

        while (!heap.isEmpty()) {
            int u = heap.extractMin();

            // Print edge when it's added to MST (except the starting node)
            if (parent[u] != -1) {
                cout << parent[u] << " -- " << u << " (" << adjMatrix[u][parent[u]] << ")" << endl;
                totalWeight += adjMatrix[u][parent[u]];
            }

            for (int v = 0; v < numVertices; v++) {
                int weight = adjMatrix[u][v];
                if (weight != INT_MAX && heap.isInMinHeap(v) && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    heap.decreaseKey(v, weight);
                }
            }
        }

        cout << "Total Cost: " << totalWeight << endl;

        // Memory management
        delete[] parent;
        delete[] key;
    }


private:
    int** adjMatrix;
    int numVertices;
};

#endif