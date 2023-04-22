class Solution {
public:
    int dp[503][2];
    int minInsertions(string s) {
        int n = s.size();
        int pos = 1;
        for (int i = n - 1; i >= 0; --i, pos ^= 1 ) {
            dp[i][pos] = 1;
            for (int j = i + 1; j < n; ++j){
                if (s[i] == s[j]){
                    dp[j][pos] = dp[j - 1][pos^1] + 2;
                }
                else {
                    dp[j][pos] = max(dp[j][pos^1], dp[j - 1][pos]);
                }
            }
        }
        return n - dp[n - 1][pos^1];
    }
};