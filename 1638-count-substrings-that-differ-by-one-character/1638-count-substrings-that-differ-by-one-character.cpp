class Solution {
public:
    
    int countSubstrings(string s, string t) {
        //dp[i][j] :  number of substrings that are equal and end s[i - 1] and t[j - 1], respectively
        //dp1[i][j] : number of substrings which end at s[i-1], t[j-1] and differe by one caracter
        
        // if (s[i - 1] == t[j - 1]) => dp[i][j] = 1 + dp[i - 1][j - 1]
        //                           => dp1[i][j] = dp1[i - 1][j - 1]
        
        //if (s[i - 1] != t[j - 1]) => dp[i][j] = 0
        //                          => dp1[i][j] = 1 + dp[i - 1][j - 1]
        int n = s.size(), m = t.size();
        int dp[n + 5][m + 5], dp1[n + 5][m + 5];
        memset(dp, 0, sizeof dp);
        memset(dp1, 0, sizeof dp1);
        
        int ans = 0;
        
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (s[i] == t[j]){
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                    dp1[i + 1][j + 1] = dp1[i][j];
                }
                else{
                    dp1[i + 1][j + 1] = 1 + dp[i][j];
                }
                ans += dp1[i + 1][j + 1];
            }
        }
        return ans;
    }
};