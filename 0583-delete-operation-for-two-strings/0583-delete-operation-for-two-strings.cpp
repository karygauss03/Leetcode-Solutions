class Solution {
public:
    int n, m;
    int dp[505][505];
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        for (int i = 0 ; i <= n ; i++) dp[i][0] = i;
        for (int j = 0 ; j <= m ; j++) dp[0][j] = j;
        for (int i = 1 ; i <= n ; i++){
            for (int j = 1 ; j <= m ; j++){
                if (word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(2 + dp[i - 1][j - 1], 1 + min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        return dp[n][m];
    }
};