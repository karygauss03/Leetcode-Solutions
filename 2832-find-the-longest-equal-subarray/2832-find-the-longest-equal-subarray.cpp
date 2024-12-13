class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int mx = 0, l = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;
            mx = max(mx, freq[nums[i]]);
            while (i - l + 1 - mx > k) {
                freq[nums[l++]]--;
            }
            ans = max(ans, mx);
        }
        return ans;
    }
};