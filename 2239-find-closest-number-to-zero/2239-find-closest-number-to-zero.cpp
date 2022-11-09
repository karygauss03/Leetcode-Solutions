class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int idx = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        if (idx == 0) return nums[0];
        if (idx >= nums.size()) return nums[nums.size() - 1];
        if (abs(nums[idx]) <= abs(nums[idx - 1])){
            return nums[idx];
        }
        if (abs(nums[idx]) > abs(nums[idx - 1])){
            return nums[idx - 1];
        }
        return 0;
    }
};