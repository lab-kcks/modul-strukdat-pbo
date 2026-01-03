#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <iomanip>
#include <algorithm>

using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V + 1) {}

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    vector<int> bfs(int src)
    {
        vector<bool> visited(V + 1, false);
        vector<int> order;
        queue<int> q;
        visited[src] = true;
        q.push(src);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            order.push_back(u);

            sort(adj[u].begin(), adj[u].end());

            for (int v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return order;
    }

    vector<int> dfs(int src)
    {
        vector<bool> visited(V + 1, false);
        vector<int> order;
        stack<int> st;
        st.push(src);

        while (!st.empty())
        {
            int u = st.top();
            st.pop();

            if (!visited[u])
            {
                visited[u] = true;
                order.push_back(u);

                sort(adj[u].rbegin(), adj[u].rend());
                for (int v : adj[u])
                {
                    if (!visited[v])
                    {
                        st.push(v);
                    }
                }
            }
        }
        return order;
    }
};

double hitungKode(const vector<int> &nodes)
{
    if (nodes.empty())
        return 0.0;
    double res = nodes[0];
    bool multiply = true;

    for (size_t i = 1; i < nodes.size(); i++)
    {
        if (multiply)
        {
            res *= nodes[i];
        }
        else
        {
            res /= nodes[i];
        }
        multiply = !multiply;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, N;
    cin >> V >> N;

    Graph g(V);

    for (int i = 0; i < N; i++)
    {
        int A, B;
        cin >> A >> B;
        g.addEdge(A, B);
    }

    int X;
    cin >> X;

    vector<int> bfsOrder = g.bfs(X);
    vector<int> dfsOrder = g.dfs(X);

    double kodeBFS = hitungKode(bfsOrder);
    double kodeDFS = hitungKode(dfsOrder);

    cout << fixed << setprecision(2) << kodeBFS << "\n"
         << kodeDFS << "\n";

    return 0;
}
