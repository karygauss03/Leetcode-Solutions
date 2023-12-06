class Solution {
public:
    int dp[100005];
    int constrainedSubsetSum(vector<int>& nums, int k) {
        memset(dp, 0, sizeof dp);
        deque<int> q;
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = nums[i] + (!q.empty() ? q.front() : 0);
            ans = max(ans, dp[i]);
            while (!q.empty() && dp[i] > q.back()) {    
                q.pop_back();
            }
            if (dp[i] > 0) {
                q.push_back(dp[i]);
            }
            if (!q.empty() && i - k >= 0 && q.front() == dp[i - k]) {
                q.pop_front();
            }
        }
        return ans;
    }
};