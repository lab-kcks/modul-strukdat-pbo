#include <iostream>
#include <vector>
using namespace std;

class FloodFiller {
    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    vector<int> component_sizes;
    size_t rows, cols;  // Use size_t for dimensions

    void validate_grid() {
        // Check maximum possible dimensions
        const size_t MAX_DIM = vector<bool>().max_size();
        
        if (rows == 0) return;  // Empty grid is allowed
        
        // Validate column consistency
        cols = grid[0].size();
        for (const auto& row : grid) {
            if (row.size() != cols) {
                throw invalid_argument("Grid is not rectangular");
            }
        }

        // Check dimension limits
        if (cols > MAX_DIM || rows > MAX_DIM) {
            throw invalid_argument("Grid dimensions exceed system limits");
        }
    }

    void dfs(size_t r, size_t c, int target) {
        if (r >= rows || c >= cols) return;
        if (visited[r][c] || grid[r][c] != target) return;

        visited[r][c] = true;
        component_sizes.back()++;

        // 4-directional flood fill with boundary checks
        if (r > 0) dfs(r - 1, c, target);     // Up
        if (r < rows - 1) dfs(r + 1, c, target); // Down
        if (c > 0) dfs(r, c - 1, target);     // Left
        if (c < cols - 1) dfs(r, c + 1, target); // Right
    }

public:
    FloodFiller(const vector<vector<int>>& input_grid) 
        : grid(input_grid),
          rows(input_grid.size()) {
        
        validate_grid();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
    }

    void find_components() {
        if (rows == 0 || cols == 0) return;  // Handle empty grid
        
        visited.assign(rows, vector<bool>(cols, false));
        component_sizes.clear();

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                if (!visited[i][j]) {
                    component_sizes.push_back(0);
                    dfs(i, j, grid[i][j]);
                }
            }
        }
    }

    void print_results() const {
        cout << "Found " << component_sizes.size() << " components:\n";
        for (size_t i = 0; i < component_sizes.size(); ++i) {
            cout << "Component " << i + 1 << ": " 
                 << component_sizes[i] << " cells\n";
        }
    }
};

int main() {
        vector<vector<int>> sample_grid = {
            {1, 1, 2, 2},
            {1, 2, 2, 2},
            {3, 3, 3, 2}
        };
        FloodFiller filler(sample_grid);
        filler.find_components();
        filler.print_results();
    return 0;
}