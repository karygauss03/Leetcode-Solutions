class Solution {
public:
    void reset(vector<vector<bool>>& vis, int n, int m) {
        for (int i = 0; i < n; ++i) {
            fill(vis[i].begin(), vis[i].end(), false);
        }
    }

    bool isOutside(int i, int j, int n, int m) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }

    int dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& grid) {
        if (isOutside(i, j, grid.size(), grid[0].size()) || vis[i][j] || grid[i][j] == 0) {
            return 0;
        }

        vis[i][j] = true;
        int sum = grid[i][j];

        sum += dfs(i - 1, j, vis, grid); // Up
        sum += dfs(i + 1, j, vis, grid); // Down
        sum += dfs(i, j - 1, vis, grid); // Left
        sum += dfs(i, j + 1, vis, grid); // Right

        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    ans = max(ans, dfs(i, j, vis, grid));
                }
            }
        }
        return ans;
    }
};
