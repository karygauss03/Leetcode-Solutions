class Solution {
public:
    int dp[205][205];
    int solve(vector<vector<int>>& grid, int i, int j = 0) {
        if (j >= grid.size() || j < 0) {
            return 0;
        }
        if (i == 0) {
            return grid[i][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for (int k = 0; k < grid.size(); ++k) {
            if (k == j) {
                continue;
            }
            ans = min(ans, grid[i][j] + solve(grid, i - 1, k));
        }
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        int ans = INT_MAX;
        for (int i = 0; i < grid.size(); ++i) {
            ans = min(ans, solve(grid, grid.size() - 1, i));
        }
        return ans;
    }
};