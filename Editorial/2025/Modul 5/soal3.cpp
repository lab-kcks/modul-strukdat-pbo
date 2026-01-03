#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;

class Graph
{
private:
    int numVertices;
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    void addEdge(int src, int dest, int weight)
    {
        adjList[src].push_back({dest, weight});
        adjList[dest].push_back({src, weight});
    }

    int primMST()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> key(numVertices, INT_MAX);
        vector<int> parent(numVertices, -1);
        vector<bool> inMST(numVertices, false);

        pq.push({0, 0});
        key[0] = 0;

        int maxCost = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u])
                continue;
            inMST[u] = true;

            if (u != 0)
            {
                maxCost = max(maxCost, key[u]);
            }

            for (auto &neighbor : adjList[u])
            {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!inMST[v] && weight < key[v])
                {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        return maxCost;
    }
};

int calculateDistance(const string &row1, const string &row2)
{
    int maxDiff = 0;
    for (int i = 0; i < row1.length(); i++)
    {
        maxDiff = max(maxDiff, abs(row1[i] - row2[i]));
    }
    return maxDiff;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    Graph g(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int distance = calculateDistance(grid[i], grid[j]);
            g.addEdge(i, j, distance);
        }
    }

    int result = g.primMST();
    cout << result << endl;

    return 0;
}