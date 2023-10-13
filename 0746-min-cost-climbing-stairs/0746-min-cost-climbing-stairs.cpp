class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int dp[1005][2];
        
        dp[0][0] = 0, dp[0][1] = 0;
        dp[1][0] = 0, dp[1][1] = 0;
        dp[1][1] = 0, dp[1][0] = cost[0];
        
        for (int i = 2 ; i <= n ; i++){
            dp[i][0] = min(cost[i - 1] + dp[i - 1][0], cost[i - 2] + dp[i - 2][0]);
            dp[i][1] = min(cost[i - 1] + dp[i - 1][1], cost[i - 2] + dp[i - 2][1]);
        }
        return min(dp[n][0], dp[n][1]);
    }
};