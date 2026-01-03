#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

class NetworkGraph
{
    int numVertices;
    vector<vector<pair<int, int>>> adjList;
    vector<int> delays;

public:
    NetworkGraph(int vertices) : numVertices(vertices), adjList(vertices + 1), delays(vertices + 1) {}

    void addEdge(int u, int v, int weight)
    {
        adjList[u].emplace_back(v, weight);
    }

    void setDelays(const vector<int> &nodeDelays)
    {
        for (int i = 0; i < nodeDelays.size() && i < numVertices; i++)
        {
            delays[i + 1] = nodeDelays[i];
        }
    }

    int networkDelayTime(int startNode)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> arrivalTime(numVertices + 1, numeric_limits<int>::max());
        vector<bool> visited(numVertices + 1, false);

        arrivalTime[startNode] = 0;
        pq.push({0, startNode});

        while (!pq.empty())
        {
            int currentTime = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (visited[u])
                continue;
            visited[u] = true;

            int sendTime = currentTime + delays[u];

            for (auto &edge : adjList[u])
            {
                int v = edge.first;
                int weight = edge.second;
                int nextArrivalTime = sendTime + weight;

                if (!visited[v] && arrivalTime[v] > nextArrivalTime)
                {
                    arrivalTime[v] = nextArrivalTime;
                    pq.push({nextArrivalTime, v});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= numVertices; ++i)
        {
            if (arrivalTime[i] == numeric_limits<int>::max())
            {
                return -1;
            }
            maxTime = max(maxTime, arrivalTime[i]);
        }

        return maxTime;
    }

    void printDebugInfo()
    {
        cout << "Network structure:" << endl;
        for (int i = 1; i <= numVertices; i++)
        {
            cout << "Node " << i << " (delay=" << delays[i] << ") -> ";
            for (const auto &edge : adjList[i])
            {
                cout << "(" << edge.first << ", weight=" << edge.second << ") ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n, k;
    cin >> n >> k;

    int m;
    cin >> m;

    NetworkGraph network(n);

    for (int i = 0; i < m; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        network.addEdge(from, to, weight);
    }

    vector<int> delays(n);
    for (int i = 0; i < n; i++)
    {
        cin >> delays[i];
    }
    network.setDelays(delays);

    int result = network.networkDelayTime(k);
    cout << result << endl;

    return 0;
}
