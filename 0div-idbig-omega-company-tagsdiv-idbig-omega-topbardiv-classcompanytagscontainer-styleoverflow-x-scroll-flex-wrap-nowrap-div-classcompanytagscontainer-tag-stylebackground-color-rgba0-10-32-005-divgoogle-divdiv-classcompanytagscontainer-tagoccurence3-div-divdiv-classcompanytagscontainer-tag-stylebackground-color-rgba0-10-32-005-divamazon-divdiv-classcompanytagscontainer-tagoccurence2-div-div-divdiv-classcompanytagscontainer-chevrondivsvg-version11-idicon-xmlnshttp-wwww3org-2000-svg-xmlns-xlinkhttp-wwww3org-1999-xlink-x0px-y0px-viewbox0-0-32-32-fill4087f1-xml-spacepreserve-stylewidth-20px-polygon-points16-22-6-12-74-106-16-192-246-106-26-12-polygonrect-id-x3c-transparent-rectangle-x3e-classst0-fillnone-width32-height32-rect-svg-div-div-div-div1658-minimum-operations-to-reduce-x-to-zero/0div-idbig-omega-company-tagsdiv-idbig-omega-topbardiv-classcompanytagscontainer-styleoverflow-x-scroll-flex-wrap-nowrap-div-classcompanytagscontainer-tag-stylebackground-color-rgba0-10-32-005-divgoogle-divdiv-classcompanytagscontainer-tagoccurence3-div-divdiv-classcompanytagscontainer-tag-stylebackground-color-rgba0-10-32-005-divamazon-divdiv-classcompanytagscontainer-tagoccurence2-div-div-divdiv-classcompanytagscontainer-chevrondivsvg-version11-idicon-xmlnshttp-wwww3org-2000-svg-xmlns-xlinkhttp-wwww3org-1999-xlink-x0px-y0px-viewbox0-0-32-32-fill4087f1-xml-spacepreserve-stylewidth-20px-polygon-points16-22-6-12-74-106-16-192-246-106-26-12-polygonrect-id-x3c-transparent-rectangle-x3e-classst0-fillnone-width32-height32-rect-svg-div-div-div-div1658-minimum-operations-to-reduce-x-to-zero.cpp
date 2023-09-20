class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totSum = 0, currSum = 0, ans = -1, n = nums.size();
        
        for (int& i : nums) totSum += i;

        for (int l = 0, r = 0; r < n; ++r) {
            currSum += nums[r];
            while (l <= r && currSum > totSum - x) {
                currSum -= nums[l++];
            }
            if (currSum == totSum - x) {
                ans = max(ans, r - l + 1);
            }
        }
        
        return ans == -1 ? -1 : n - ans;
    }
};