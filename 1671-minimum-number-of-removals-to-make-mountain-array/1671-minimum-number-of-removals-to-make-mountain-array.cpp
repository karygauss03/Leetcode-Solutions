class Solution {
private:
    int solve(int i, int n, vector<int>& dp, vector<int>& nums, bool reversed = false) {
        if (i == 0 && !reversed) {
            return dp[i] = 1;
        }
        if (reversed && i == n - 1) {
            return dp[i] = 1;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int cur = 1;
        if (!reversed) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    cur = max(cur, 1 + solve(j, n, dp, nums));
                }
            }
            return dp[i] = cur;
        }
        
        for (int j = n - 1; j > i; --j) {
            if (nums[j] < nums[i]) {
                cur = max(cur, 1 + solve(j, n, dp, nums));
            }
        }
        return dp[i] = cur;
    }
    

public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        if (n == 3) {
            return 0;
        } 
        vector<int> dp(n, -1);
        vector<int> dp2(n, -1);
        
        // dp[i] = LIS (0, i)
        for (int i = 0; i < n; ++i) {
            solve(i, n, dp, nums);
        }
        
        // dp2[i] = LIS(n - 1, i) reversed
        for (int i = n - 1; i >= 0; --i) {
            solve(i, n, dp2, nums, true);
        }
        int ans = n;
        for (int i = 1; i < n - 1; ++i) {
            if (dp[i] > 1 && dp2[i] > 1) {
                ans = min(ans, n - (dp[i] + dp2[i] - 1));
            }
        }

        return ans;

    }
};