#include<bits/stdc++.h>

class Solution {
private:
    int n, m;
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == n || j == m) {
            return INT_MAX;
        }

        if (i == (n - 1) && j == (m - 1)) {
            return grid[i][j] < 0 ? -grid[i][j] + 1 : 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve(i, j + 1, grid, dp);
        int down = solve(i + 1, j, grid, dp);
        int mn = min(right, down) - grid[i][j];
        return dp[i][j] = mn <= 0 ? 1 : mn;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, grid, dp);
    }
};