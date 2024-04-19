class Solution {
public:
    int n, m;
    bool vis[305][305];
    
    void dfs(int r, int c, vector<vector<char>> &grid){
        
        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == '0' || vis[r][c] == true) return;
        vis[r][c] = true;
        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(vis, false, sizeof vis);
        
        int ans = 0;
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (!vis[i][j] && grid[i][j] == '1'){
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};