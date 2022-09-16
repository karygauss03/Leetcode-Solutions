class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<int> dp(multipliers.size() + 1, 0);
        for(int k = multipliers.size()-1; k>=0; k--){
            for(int i = 0; i <= k; i++){
                dp[i] = max(dp[i] + nums[nums.size() - 1 + i - k]*multipliers[k], dp[i+1] + nums[i]*multipliers[k]);
            }
        }
        return dp[0];
    }
};