class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(2,vector<int>(n + 1,INT_MAX-1)); // dp[i][j] => we have egg j at floor i
        dp[0][0] = 0;
        dp[1][0] = 0;
        for (int i = 1 ; i <= n ; i++){
            dp[0][i] = i;
        }
        for (int i = 1 ; i <= n ; i++){
            for (int j = 1 ; j <= i ; j++){
                dp[1][i] = min(max(dp[0][j - 1],dp[1][i - j]) + 1, dp[1][i]);    
            }
        }
        return dp[1][n];
    }
};