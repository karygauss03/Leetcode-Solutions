class Solution {
public:
    int n, m;
    bool vis[55][55];
    int ans = 0;
    int dfs(int r, int c, vector<vector<int>>& grid){
        if (r < 0 || c < 0 || r >= n || c >= m || vis[r][c] == true || grid[r][c] == 0) {
            return 0;
        }
        vis[r][c] = true;
        return 1 + dfs(r + 1, c, grid) + dfs(r - 1, c, grid) + dfs(r, c + 1, grid) + dfs(r, c - 1, grid);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(vis, 0, sizeof vis);
        for (int i = 0 ; i < n; i++){
            for (int j = 0 ; j < m ; j++){
                if (!vis[i][j] && grid[i][j] == 1){
                    ans = max(ans,dfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};