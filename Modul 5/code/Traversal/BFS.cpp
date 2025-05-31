#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;

public:
    // Constructor
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    // Function to add an edge to the graph
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // For undirected graph
    }

    // BFS function
    void BFS(int startVertex) {
        queue<int> queue;
        unordered_set<int> visited;

        // Mark the starting vertex as visited and enqueue it
        visited.insert(startVertex);
        queue.push(startVertex);

        while (!queue.empty()) {
            int currentVertex = queue.front();
            queue.pop();
            cout << currentVertex << " ";

            // Visit all adjacent vertices of the current vertex
            for (int adjacentVertex : adjList[currentVertex]) {
                if (visited.find(adjacentVertex) == visited.end()) {
                    visited.insert(adjacentVertex);
                    queue.push(adjacentVertex);
                }
            }
        }
    }
};

int main() {
    // Create a graph with 6 vertices
    Graph graph(6);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    // Perform BFS starting from vertex 0
    cout << "BFS starting from vertex 0: ";
    graph.BFS(0);

    return 0;
}