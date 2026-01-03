#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

using Point = pair<int, int>;

class TreasureFinder
{
private:
    int cols, rows;
    vector<string> grid;
    set<Point> all_treasures;
    vector<Point> accessible_treasures;
    Point start_pos = {-1, -1};

    bool isTreasure(int r, int c)
    {
        if (grid[r][c] == '#')
            return false;

        int wall_count = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '#')
            {
                wall_count++;
            }
        }

        return wall_count == 3;
    }

    void findTreasuresAndStart()
    {
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c] == '*')
                {
                    start_pos = {r, c};
                }
                if (isTreasure(r, c))
                {
                    all_treasures.insert({r, c});
                }
            }
        }
    }

    void bfs()
    {
        queue<Point> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        q.push(start_pos);
        visited[start_pos.first][start_pos.second] = true;

        while (!q.empty())
        {
            Point current = q.front();
            q.pop();

            if (all_treasures.count(current))
            {
                accessible_treasures.push_back(current);
            }

            int r = current.first;
            int c = current.second;
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                    grid[nr][nc] != '#' && !visited[nr][nc])
                {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    void outputResult()
    {
        sort(accessible_treasures.begin(), accessible_treasures.end(),
             [](const Point &a, const Point &b)
             {
                 return (a.second != b.second) ? (a.second < b.second) : (a.first < b.first);
             });

        cout << accessible_treasures.size() << endl;
        for (const auto &p : accessible_treasures)
        {
            cout << p.second << " " << p.first << endl;
        }
    }

public:
    void run()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        cin >> cols >> rows;
        grid.resize(rows);
        for (int i = 0; i < rows; ++i)
        {
            cin >> grid[i];
        }

        findTreasuresAndStart();
        bfs();
        outputResult();
    }
};

int main()
{
    TreasureFinder tf;
    tf.run();
    return 0;
}
