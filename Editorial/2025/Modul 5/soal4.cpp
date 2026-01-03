#include <iostream>
#include <vector>

using namespace std;

class Kuil
{
private:
    int N, B, buntuCount = 0;
    vector<vector<int>> adj;
    vector<int> finalPath;
    bool foundBalkon = false;

public:
    Kuil(int n, int b) : N(n), B(b), adj(n + 1) {}

    void addDoors(int ruangan, const vector<int> &pintu)
    {
        for (int tujuan : pintu)
        {
            if (tujuan != 0)
                adj[ruangan].push_back(tujuan);
        }
    }

    void dfs(int current, vector<int> &path, vector<bool> &visited)
    {
        if (foundBalkon)
            return;

        visited[current] = true;
        path.push_back(current);

        if (current == B)
        {
            finalPath = path;
            foundBalkon = true;
            return;
        }

        bool buntu = true;
        for (int next : adj[current])
        {
            if (!visited[next])
            {
                dfs(next, path, visited);
                if (foundBalkon)
                    return;
                buntu = false;
            }
        }

        if (buntu)
        {
            buntuCount++;
        }

        path.pop_back();
        visited[current] = false;
    }

    void findPath(int start)
    {
        vector<bool> visited(N + 1, false);
        vector<int> path;
        dfs(start, path, visited);
    }

    void printResult() const
    {
        cout << buntuCount << '\n';
        for (size_t i = 0; i < finalPath.size(); i++)
        {
            cout << finalPath[i];
            if (i + 1 < finalPath.size())
                cout << ' ';
        }
        cout << '\n';
    }
};

int main()
{
    int N, S, B;
    cin >> N >> S >> B;

    Kuil kuil(N, B);

    for (int i = 1; i <= N; ++i)
    {
        vector<int> pintu;
        while (true)
        {
            int x;
            cin >> x;
            if (x == 0)
                break;
            pintu.push_back(x);
        }
        kuil.addDoors(i, pintu);
    }

    kuil.findPath(S);
    kuil.printResult();

    return 0;
}
