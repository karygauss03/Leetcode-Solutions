class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int solve(int i, int j, int &n, int &m, vector<vector<int>>&grid, vector<vector<int>>&dp)
    {
        if (i < 0 or j < 0 or i >= n or j >= m)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int up = 0, down = 0, left = 0, right = 0;
        
        if (i - 1 >= 0 and grid[i - 1][j] > grid[i][j])
            up = solve(i - 1, j, n, m, grid, dp);
        
        if (i + 1 < n and grid[i + 1][j] > grid[i][j])
            down = solve(i + 1, j, n, m, grid, dp);
        
        if (j - 1 >= 0 and grid[i][j - 1] > grid[i][j])
            left = solve(i, j - 1, n, m, grid, dp);
        
        if (j + 1 < m and grid[i][j + 1] > grid[i][j])
            right = solve(i, j + 1, n, m, grid, dp);
        
        return dp[i][j] = (1 + up + down + left + right) % MOD;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        
        int ans = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = (ans + solve(i, j, n, m, grid, dp)) % MOD;
            }
        }
        
        return ans % MOD;
    }
};