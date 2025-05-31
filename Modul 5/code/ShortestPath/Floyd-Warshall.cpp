#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Graph {
    int numVertices;
    vector<vector<int>> dist;

public:
    Graph(int vertices) : numVertices(vertices), 
                         dist(vertices, vector<int>(vertices, numeric_limits<int>::max())) {
        // Initialize diagonal with 0 (distance to self)
        for (int i = 0; i < vertices; ++i) {
            dist[i][i] = 0;
        }
    }

    void addEdge(int u, int v, int weight) {
        dist[u][v] = weight;
    }

    void floydWarshall() {
        // Main algorithm
        for (int k = 0; k < numVertices; ++k) {
            for (int i = 0; i < numVertices; ++i) {
                for (int j = 0; j < numVertices; ++j) {
                    if (dist[i][k] != numeric_limits<int>::max() && 
                        dist[k][j] != numeric_limits<int>::max()) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Check for negative cycles
        if (hasNegativeCycle()) {
            cout << "Graph contains negative weight cycle!\n";
            return;
        }

        printSolution();
    }

private:
    bool hasNegativeCycle() {
        for (int i = 0; i < numVertices; ++i) {
            if (dist[i][i] < 0) return true;
        }
        return false;
    }

    void printSolution() {
        cout << "Shortest distances between every pair of vertices:\n";
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (dist[i][j] == numeric_limits<int>::max()) {
                    cout << "INF\t";
                } else {
                    cout << dist[i][j] << "\t";
                }
            }
            cout << "\n";
        }
    }
};

int main() {
    // Test case 1: No negative cycle
    Graph g1(4);
    g1.addEdge(0, 1, 5);
    g1.addEdge(0, 3, 10);
    g1.addEdge(1, 2, 3);
    g1.addEdge(2, 3, 1);
    
    cout << "Test case 1:\n";
    g1.floydWarshall();

    // Test case 2: With negative cycle
    Graph g2(3);
    g2.addEdge(0, 1, 2);
    g2.addEdge(1, 2, -4);
    g2.addEdge(2, 0, 1);  // Creates negative cycle
    
    cout << "\nTest case 2:\n";
    g2.floydWarshall();

    return 0;
}