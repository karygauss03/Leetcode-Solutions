class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = nums[0], cur, ans = 0;
        for (int i = 1; i < nums.size(); ++i) {
            cur = nums[i];
            if (cur > prev) {
                prev = cur;
                continue;
            }
            nums[i] += (prev - cur + 1);
            ans += (prev - cur + 1);
            prev = nums[i];
        }
        return ans;
    }
};