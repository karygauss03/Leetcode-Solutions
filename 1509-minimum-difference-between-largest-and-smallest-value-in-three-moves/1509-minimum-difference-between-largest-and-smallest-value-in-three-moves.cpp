class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int l = 3, r = 0, ans = INT_MAX;
        while (l >= 0) {
            ans = min(ans, nums[nums.size() - 1 - r] - nums[l]);
            ++r, --l;
        }
        return ans;
    }
};

// 20 75 81 82 95
