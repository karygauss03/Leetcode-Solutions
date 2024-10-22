class Solution {
private:
    int dp[10005];
    int solve(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        if (amount < 0) {
            return INT_MAX;
        }

        if (dp[amount] != -1) {
            return dp[amount];
        }
        dp[amount] = INT_MAX;

        for (auto& coin : coins) {
            int cur = solve(coins, amount - coin);
            if (cur != INT_MAX){
                dp[amount] = min(dp[amount], 1 + solve(coins, amount - coin));
            }
        }
        return dp[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof dp);
        int ans = solve(coins, amount);
        if (ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};