class Solution {
public:
    static const int MOD = 1000000007;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long long ans = 1;
        vector<int> onesPositions;
        
        bool found = false;
        for (int i = 0 ; i < nums.size() ; ++i) {
            if (nums[i] == 1) {
                onesPositions.push_back(i);
            }
        }
        if (!onesPositions.size())
            return 0;
        
        for (int i = 1 ; i < onesPositions.size() ; ++i) {
            ans *= (onesPositions[i] - onesPositions[i - 1]) % MOD;
            ans %= MOD;
        }
        return ans % MOD;
    }
};