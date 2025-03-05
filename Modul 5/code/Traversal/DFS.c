#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;

    // Fungsi helper rekursif untuk DFS
    void DFSUtil(int current, unordered_set<int>& visited) {
        visited.insert(current);
        cout << current << " ";

        // Kunjungi semua node yang terhubung dengan node saat ini
        for (int adjacent : adjList[current]) {
            if (visited.find(adjacent) == visited.end()) {
                DFSUtil(adjacent, visited);
            }
        }
    }

public:
    // Constructor
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    // Menambahkan edge ke graf (undirected)
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    // Fungsi DFS utama
    void DFS(int start) {
        unordered_set<int> visited;
        DFSUtil(start, visited);
    }
};

int main() {
    // Membuat graf dengan 6 node
    Graph graph(6);

    // Menambahkan edge
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    // Menjalankan DFS mulai dari node 0
    cout << "DFS traversal mulai dari node 0: ";
    graph.DFS(0);

    return 0;
}