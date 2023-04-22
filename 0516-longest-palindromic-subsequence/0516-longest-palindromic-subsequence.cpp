class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> dp(n), dpPrev(n);

        for (int start = n - 1; start >= 0; --start) {
            dp[start] = 1;
            for (int end = start + 1; end < n; ++end) {
                if (s[start] == s[end]) {
                    dp[end] = dpPrev[end - 1] + 2;
                } else {
                    dp[end] = max(dpPrev[end], dp[end - 1]);
                }
            }
            dpPrev = dp;
        }
        return dp[n - 1];
    }
};