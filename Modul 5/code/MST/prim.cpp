#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<pair<int, int>>> adjList;  // Format: (destination, weight)

public:
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    // Menambahkan edge berbobot ke graf (undirected)
    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back({dest, weight});
        adjList[dest].push_back({src, weight});
    }

    // Algoritma Prim untuk mencari MST
    void primMST() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> key(numVertices, INT_MAX);
        vector<int> parent(numVertices, -1);
        vector<bool> inMST(numVertices, false);

        // Mulai dari vertex 0
        pq.push({0, 0});
        key[0] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            // Iterasi semua tetangga
            for (auto &neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // Update key jika menemukan edge yang lebih kecil
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        // Cetak MST
        cout << "Edge \tBobot\n";
        int totalWeight = 0;
        for (int i = 1; i < numVertices; ++i) {
            cout << parent[i] << " - " << i << "\t  " << key[i] << endl;
            totalWeight += key[i];
        }
        cout << "Total bobot MST: " << totalWeight << endl;
    }
};

int main() {
    Graph g(6);

    // Menambahkan edge dengan bobot
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 5, 3);
    g.addEdge(4, 5, 3);

    g.primMST();

    return 0;
}