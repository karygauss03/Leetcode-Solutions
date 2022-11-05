class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {        
        int rows = grid.size(), cols = grid[0].size(); // get the size of rows and cols
        vector<vector<int>> dp(rows, vector<int>(cols, 0)); // initialize dp
        dp[0] = grid[0]; int ans = INT_MAX; // intialize dp[0]
        // apply DP algorithm as explained above
        for (int i = 1; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                int cur = INT_MAX;
                for (int k = 0; k < cols; ++k){
                    cur = min(cur, dp[i - 1][k] + moveCost[grid[i - 1][k]][j]);
                }
                dp[i][j] = grid[i][j] + cur;
                if (i == rows - 1) ans = min(ans, dp[i][j]); // store the minimum answer for the last row
            }
        }
        return ans;
    }
};