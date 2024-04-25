class Solution {
public:
    int solve(vector<vector<int>> &dp, string& s, int i, int& k, char prev = '*') {
        if (s.size() == i) {
            return 0;
        }
        if (prev == '*') {
            return max(1 + solve(dp, s, i + 1, k, s[i]), solve(dp, s, i + 1, k));
        }
        
        if (dp[i][prev - 'a'] != -1) {
            return dp[i][prev - 'a'];
        }
        
        if (abs(s[i] - prev) <= k) {
            return dp[i][prev - 'a'] = max(1 + solve(dp, s, i + 1, k, s[i]), solve(dp, s, i + 1, k, prev));
        }
        return dp[i][prev - 'a'] = solve(dp, s, i + 1, k, prev);
    }
    
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(26, -1));
        return solve(dp, s, 0, k);
    }
};