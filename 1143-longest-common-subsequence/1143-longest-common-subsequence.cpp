class Solution {
public:
    int dp[1005][1005];
    int n, m;
    
    
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size(), m = text2.size();
        memset(dp, 0, sizeof dp);
        
        
        for (int i = 1 ; i <= n ; i++){
            for (int j = 1 ; j <= m ; j++){
                if (text1[i - 1] == text2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][m];
        
    }
};