class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        int n = nums.size(), cnt = 1;
        vector<int> ans(n - k + 1, -1);
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] == nums[i] + 1) {
                ++cnt;
            }
            else {
                cnt = 1;
            }
            if (cnt >= k) {
                ans[i - k + 2] = nums[i + 1];
            }
        }
        return ans;
    }
};