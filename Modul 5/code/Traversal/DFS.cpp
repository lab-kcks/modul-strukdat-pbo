#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;
    vector<bool> visited;

    // Private recursive DFS helper method
    void dfsFromVertex(int currentNode) {
        if (visited[currentNode]) { 
            return; 
        }
        
        cout << currentNode << " ";
        visited[currentNode] = true;

        for (int neighbor : adjList[currentNode]) {
            dfsFromVertex(neighbor);
        }
    }

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

    // DFS traversal for all connected components
    void dfsTraversal() {
        resetVisited();
        
        for (int i = 0; i < numVertices; i++) {
            // Iterate over all connected components in the graph
            if (!visited[i]) { 
                dfsFromVertex(i); 
            }
        }
    }

    // DFS traversal starting from a specific vertex
    void dfsFromStart(int startVertex) {
        resetVisited();
        dfsFromVertex(startVertex);
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

    // Define adjacency list and read in problem-specific input
    // In this example, we've provided "dummy input" that's
    // reflected in the order of the recursive calls.
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 4);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);

    cout << "Graph structure:" << endl;
    graph.displayGraph();
    
    cout << "\nDFS Traversal: ";
    graph.dfsTraversal();
    cout << endl;

    return 0;
}