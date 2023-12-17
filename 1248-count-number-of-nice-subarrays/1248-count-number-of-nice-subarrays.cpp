class Solution {
private:
    int solve(vector<int> &nums, int k) {
        int ans = 0;
        int l = 0, r = 0;
        while (r < nums.size()) {
            k -= nums[r] % 2;
            while (k < 0) {
                k += nums[l] % 2;
                ++l;
            }
            ans += r - l + 1;
            ++r;
        }
        return ans;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};