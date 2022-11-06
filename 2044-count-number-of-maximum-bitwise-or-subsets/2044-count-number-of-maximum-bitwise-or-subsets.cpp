class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        int dp[1<<17] = {1};
        for (auto &num : nums){
            for (int i = max_or ; i >= 0 ; i--){
                dp[i|num] += dp[i]; 
            }
            max_or |= num;
        }
        return dp[max_or];
    }
};