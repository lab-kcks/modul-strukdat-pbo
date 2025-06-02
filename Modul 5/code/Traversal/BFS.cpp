#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;
    vector<bool> visited;

public:
    // Constructor
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
        visited.resize(vertices, false);
    }

    // Add edge to the graph
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }

    // Reset visited array for new traversal
    void resetVisited() {
        fill(visited.begin(), visited.end(), false);
    }

    // BFS traversal starting from a given vertex
    void bfsFromVertex(int startVertex) {
        queue<int> q;
        q.push(startVertex);
        visited[startVertex] = true;

        while (!q.empty()) {
            int currentNode = q.front();
            cout << currentNode << " ";
            q.pop();

            for (int neighbor : adjList[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    // BFS traversal for all connected components
    void bfsTraversal() {
        resetVisited();
        
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                bfsFromVertex(i);
            }
        }
    }

    // Display the adjacency list
    void displayGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(6);

    // Add edges as per the original example
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 4);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);

    cout << "Graph structure:" << endl;
    graph.displayGraph();
    
    cout << "\nBFS Traversal: ";
    graph.bfsTraversal();
    cout << endl;

    return 0;
}