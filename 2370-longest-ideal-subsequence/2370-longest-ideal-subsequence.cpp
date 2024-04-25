class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size(), dp[150] = {}, ans = 0;
        for (auto &c : s) {
            for (int j = c - k; j <= c + k; ++j) {
                dp[c] = max(dp[c], dp[j]);
            }
            ans = max(ans, ++dp[c]);
        }
        return ans;
    }
};