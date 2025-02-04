class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int cur = nums[0], ans = -1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                cur += nums[i];
            }
            else {
                ans = max(ans, cur);
                cur = nums[i];
            }
        }
        return max(ans, cur);
    }
};