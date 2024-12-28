class Solution {
private:
    int solve(int i, int k, int j, vector<vector<int>>& dp, int n, vector<int>& a) {
        if (j == 0) return 0;
        if (i >= n) {
            return j == 0 ? 0 : INT_MIN;
        }
        if (dp[i][j] != -1) return dp[i][j];

        int take = a[i] + solve(i + k, k, j - 1, dp, n, a);
        int leave = solve(i + 1, k, j, dp, n, a);
        return dp[i][j] = max(take, leave);
    }

    void work(vector<int>& a, int k, int i, int j, vector<vector<int>>& dp, vector<int>& ans, int n) {
        if (j == 0) return;
        if (i >= n) return;
        int take = a[i] + solve(i + k, k, j - 1, dp, n, a);
        int leave = solve(i + 1, k, j, dp, n, a);

        if (take >= leave) {
            ans.push_back(i);
            work(a, k, i + k, j - 1, dp, ans, n);
        }
        else {
            work(a, k, i + 1, j, dp, ans, n);
        }
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size() - k + 1;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        a[0] = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum = sum - nums[i - k] + nums[i];
            a[i - k + 1] = sum;
        }
        vector<vector<int>> dp(n, vector<int>(4, -1));
        solve(0, k, 3, dp, n, a);
        vector<int> ans;
        work(a, k, 0, 3, dp, ans, n);
        return ans;
    }
};