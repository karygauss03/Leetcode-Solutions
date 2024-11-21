class Solution {
private:
    void upd(vector<vector<int>>& grid, int i, int j) {
        for (int r = i + 1; r < grid.size(); ++r) {
            if (grid[r][j] >= 1) {
                break;
            }
            grid[r][j] = 0;
        }

        for (int r = i - 1; r >= 0; --r) {
            if (grid[r][j] >= 1) {
                break;
            }
            grid[r][j] = 0;
        }

        for (int c = j + 1; c < grid[0].size(); ++c) {
            if (grid[i][c] >= 1) {
                break;
            }
            grid[i][c] = 0;
        }

        for (int c = j - 1; c >= 0; --c) {
            if (grid[i][c] >= 1) {
                break;
            }
            grid[i][c] = 0;
        }
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        swap(m, n);
        vector<vector<int>> grid(n, vector<int>(m, -1));
        // -1: not guarded
        // 0: guarded
        // 1: guard
        // 2: wall
        for (auto &g : guards) {
            grid[g[0]][g[1]] = 1;
        }
        for (auto &w : walls) {
            grid[w[0]][w[1]] = 2;
        }

        for (auto &g : guards) {
            int i = g[0], j = g[1];
            upd(grid, i, j);
        }
        
        int unguarded = 0;
        for (const auto& row : grid) {
            unguarded += count(row.begin(), row.end(), -1);
        }

        return unguarded;
    }
};