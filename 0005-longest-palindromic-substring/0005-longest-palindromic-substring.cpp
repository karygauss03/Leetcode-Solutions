class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) {
            return s;
        }
        
        int dp[n + 5][n + 5];
        string ans = "";
        memset(dp, 0, sizeof dp);
        for (int i = n - 1 ; i >= 0 ; --i){
            for (int j = i ; j < n ; ++j){
                if (i == j) dp[i][j] = 1;
                else if (j - i == 1 && s[i] == s[j]){
                    dp[i][j] = 1;
                }
                else if (s[i] == s[j] && dp[i + 1][j - 1] == 1){
                    dp[i][j] = 1;
                }
                
                if (dp[i][j] == 1 && j - i + 1 > ans.size()){
                    ans =  s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }
};