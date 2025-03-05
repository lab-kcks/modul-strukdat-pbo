#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Graph {
    struct Edge {
        int source;
        int destination;
        int weight;
    };

    int numVertices;
    vector<Edge> edges;

public:
    Graph(int vertices) : numVertices(vertices) {}

    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    void bellmanFord(int startNode) {
        vector<int> distances(numVertices, numeric_limits<int>::max());
        distances[startNode] = 0;

        // Relax all edges (V-1) times
        for (int i = 1; i < numVertices; ++i) {
            for (const auto& edge : edges) {
                if (distances[edge.source] != numeric_limits<int>::max() &&
                    distances[edge.destination] > distances[edge.source] + edge.weight) {
                    distances[edge.destination] = distances[edge.source] + edge.weight;
                }
            }
        }

        // Check for negative-weight cycles
        bool hasNegativeCycle = false;
        for (const auto& edge : edges) {
            if (distances[edge.source] != numeric_limits<int>::max() &&
                distances[edge.destination] > distances[edge.source] + edge.weight) {
                hasNegativeCycle = true;
                break;
            }
        }

        if (hasNegativeCycle) {
            cout << "Graph contains negative weight cycle reachable from source!\n";
        } else {
            cout << "Shortest distances from node " << startNode << ":\n";
            for (int i = 0; i < numVertices; ++i) {
                if (distances[i] == numeric_limits<int>::max()) {
                    cout << "Node " << i << ": Unreachable\n";
                } else {
                    cout << "Node " << i << ": " << distances[i] << "\n";
                }
            }
        }
    }
};

int main() {
    // Test case 1: No negative cycle
    Graph g1(5);
    g1.addEdge(0, 1, 4);
    g1.addEdge(0, 2, 2);
    g1.addEdge(1, 3, 2);
    g1.addEdge(2, 1, 1);
    g1.addEdge(2, 3, 5);
    g1.addEdge(2, 4, 3);
    g1.addEdge(3, 4, -3);

    cout << "Test case 1:\n";
    g1.bellmanFord(0);

    // Test case 2: With negative cycle
    Graph g2(3);
    g2.addEdge(0, 1, 3);
    g2.addEdge(1, 2, -2);
    g2.addEdge(2, 0, -2); // Creates negative cycle

    cout << "\nTest case 2:\n";
    g2.bellmanFord(0);

    return 0;
}