class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 0;
        long sum = 0L;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            sum += nums[r];
            while ((sum + k) < (long(r - l + 1) * nums[r])) sum -= nums[l++];
            result = max(result, r - l + 1);
        }
        return result;
    }
};