class Solution {
public:
    int n, m;
    int dp[1005][1005];
    int minimumDeleteSum(string s1, string s2) {
        n = s1.size(), m = s2.size();
        memset(dp, 0, sizeof dp);
        for (int j = 1; j <= m; j++)
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        for (int i = 1 ; i <= n ; i++){
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
            for (int j = 1 ; j <= m ; j++){
                if (s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};