class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long prefix[n], sum = nums[0];
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
            sum += nums[i];
        }
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (prefix[i] >= sum - prefix[i]) {
                ++ans;   
            }
        }
        return ans;
    }
};