class Solution {
public:
    int dp[205][205];
    
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid){
        if (i > n - 1 || j > m - 1) return 500;
        if (i == n - 1 && j == m - 1) return grid[n - 1][m - 1];
        int &res = dp[i][j];
        if (res != -1) return res;
        
        return res = min(grid[i][j] + solve(i, j + 1, n, m, grid), grid[i][j] + solve(i + 1, j, n, m, grid));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        memset(dp, -1, sizeof dp);
        
        return solve(0, 0, n, m, grid);
    }
};