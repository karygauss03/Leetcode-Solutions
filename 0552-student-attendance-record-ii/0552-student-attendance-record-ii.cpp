class Solution {
public:
    const static int MOD = 1e9 + 7;
    int dp[100005][2][3];
    int checkRecord(int n) {
        memset(dp, 0, sizeof dp);
        dp[0][0][0] = 1;
        
        for (int i = 0; i < n; ++i) {
            for (int abs = 0; abs <= 1; ++abs) {
                for (int late = 0; late <= 2; ++late) {
                    dp[i + 1][abs][0] = (dp[i + 1][abs][0] + dp[i][abs][late]) % MOD; 
                    
                    if (abs < 1) {
                        dp[i + 1][abs + 1][0] = (dp[i + 1][abs + 1][0] + dp[i][abs][late]) % MOD;
                    }

                    if (late < 2) {
                        dp[i + 1][abs][late + 1] = (dp[i + 1][abs][late + 1] + dp[i][abs][late]) % MOD;
                    }
                }
            }
        }
        int ans = 0;
        for(int abs = 0; abs <= 1; ++abs) {
            for (int late = 0; late <= 2; ++late) {
                ans = (ans + dp[n][abs][late]) % MOD;
            }
        }
        
        return ans;
    }
};