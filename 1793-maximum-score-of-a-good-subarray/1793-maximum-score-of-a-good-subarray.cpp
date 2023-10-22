class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int minimumElement = nums[k];
        int i = k, j = k;
        int ans = minimumElement * (j - i + 1);
        while (i > 0 || j < nums.size() - 1) {
            if (i == 0 || (j < nums.size() - 1 && nums[j + 1] > nums[i - 1])) {
                ++j;
            }
            else {
                --i;
            }
            minimumElement = min(minimumElement, min(nums[i], nums[j]));
            ans = max(ans, minimumElement * (j - i + 1));
        }
        return ans;
    }
};