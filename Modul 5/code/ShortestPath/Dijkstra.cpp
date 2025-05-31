#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Graph {
    int numVertices;
    vector<vector<pair<int, int>>> adjList; // Pair: (node, weight)

public:
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight); // For undirected graph
    }

    void dijkstra(int startNode) {
        // Priority queue to store (distance, node) pairs
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> dist(numVertices, numeric_limits<int>::max());
        vector<bool> visited(numVertices, false);

        // Initialize start node
        dist[startNode] = 0;
        pq.push({0, startNode});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            // Skip if already visited with shorter distance
            if (visited[u]) continue;
            visited[u] = true;

            for (auto &edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (!visited[v] && dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print shortest distances
        cout << "Shortest distances from node " << startNode << ":\n";
        for (int i = 0; i < numVertices; ++i) {
            if (dist[i] == numeric_limits<int>::max())
                cout << "Node " << i << ": Unreachable\n";
            else
                cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }
};

int main() {
    Graph g(6);
    
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 5);
    g.addEdge(0, 3, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 3);

    g.dijkstra(0);

    return 0;
}