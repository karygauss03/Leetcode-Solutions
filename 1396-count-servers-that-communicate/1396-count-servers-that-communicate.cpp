class Solution {
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, int& count) {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = true;
        count++;
        for (int col = 0; col < m; ++col) {
            if (grid[i][col] == 1 && !vis[i][col]) {
                dfs(i, col, grid, vis, count);
            }
        }
        for (int row = 0; row < n; ++row) {
            if (grid[row][j] == 1 && !vis[row][j]) {
                dfs(row, j, grid, vis, count);
            }
        }
    }

public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int count = 0;
                    dfs(i, j, grid, vis, count);
                    if (count > 1) {
                        ans += count;
                    }
                }
            }
        }
        return ans;
    }
};
