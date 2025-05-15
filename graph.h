#ifndef GRAPH_H
#define GRAPH_H
using namespace std; // added for print(cout)

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
        // Keeps track of which vertices were visited
        bool visited[numVertices];
        // Stores key values
        int key[numVertices];
        // Stores index of the parent value (needed to print starting vertex)
        int parent[numVertices];
        // All keys start off as infinity and none of the vertices are in the MST
        for (int i = 0; i < numVertices; i++) {
            key[i] = INT_MAX;
            visited[i] = false;
        }

        // Set starting index as 0
        key[0] = 0;
        parent[0] = -1;

        int total_cost = 0;

        for (int count = 0; count < numVertices; count++) {
            // Pick the minimum key vertex from the set of vertices not yet included in MST
            int u = -1;
            int min = INT_MAX;
            for (int v = 0; v < numVertices; v++) {
                if (!visited[v] && key[v] < min) {
                    min = key[v];
                    u = v;
                }
            }

            // Add the vertex to the array that stores visited vertices
            visited[u] = true;

            // Print the edge that was added to MST so that it prints in order
            if (parent[u] != -1) {
                cout << parent[u] << " -- " << u << " (" << adjMatrix[parent[u]][u] << ")" << endl;
                total_cost += adjMatrix[parent[u]][u];
            }

            for (int v = 0; v < numVertices; v++) {
                // Decrease edge weight if neighbor is unvisited and its key value is less than the current key value
                if (adjMatrix[u][v] != 0 && !visited[v] && adjMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                }
            }
        }

        // Print the total cost
        cout << "Total Cost: " << total_cost << endl;
    }

private:
    int** adjMatrix;
    int numVertices;
};

#endif