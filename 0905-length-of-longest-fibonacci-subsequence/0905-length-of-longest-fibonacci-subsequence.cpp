class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            int l = 0, r = i - 1;
            while (l < r) {
                int nxt = arr[l] + arr[r];
                if (nxt > arr[i]) --r;
                else if (nxt < arr[i]) ++l;
                else {
                    dp[r][i] = dp[l][r] + 1;
                    ans = max(ans, dp[r][i]);
                    --r;
                    ++l;
                }
            }
        }
        return ans == 0 ? 0 : ans + 2;
    }
};