class Solution {
private:
    int n, m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    bool isInGrid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j) {
        if (!isInGrid(i, j) || vis[i][j]) {
            return;
        }
        vis[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            if (isInGrid(i + dx[k], j + dy[k]) && grid[i + dx[k]][j + dy[k]] && !vis[i + dx[k]][j + dy[k]]) {
                dfs(grid, vis, i + dx[k], j + dy[k]);
            }
        }
    }
    
    int countIsland(vector<vector<int>>& grid) {
        int islandCount = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && !vis[i][j]) {
                    ++islandCount;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return islandCount;
    }
    
public:
    int minDays(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        if (countIsland(grid) != 1) {
            return 0;
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    if (countIsland(grid) != 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                } 
            }
        }
        return 2;
    }
};