#ifndef GRAPH_H
#define GRAPH_H
using namespace std;

class Graph {
public:
    Graph(int vertices) {
        int inf = INT_MAX;
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
        // if directed delete:
        adjMatrix[v][u] = weight;
    }

    void primMST() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << i << ", "<< j << ", " << adjMatrix[i][j] << endl;
            }
        }
        // Must print MST edges and total weight
    }

private:
    int** adjMatrix;
    int numVertices;
};

#endif