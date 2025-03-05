#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int main() {
    int n = 4; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int cost = 0;
    vector<int> tree_id(n);
    vector<Edge> result;

    // Initialize each vertex as its own component
    for (int i = 0; i < n; i++) {
        tree_id[i] = i;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    // Iterate through sorted edges
    for (Edge e : edges) {
        if (tree_id[e.u] != tree_id[e.v]) {
            cost += e.weight;
            result.push_back(e);

            // Merge components
            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n; i++) {
                if (tree_id[i] == old_id) {
                    tree_id[i] = new_id;
                }
            }
        }
    }

    // Output the MST
    cout << "Edges in MST:\n";
    for (Edge e : result) {
        cout << e.u << " - " << e.v << " : " << e.weight << "\n";
    }
    cout << "Total Weight: " << cost << endl;

    return 0;
}