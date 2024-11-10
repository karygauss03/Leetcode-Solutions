class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = nums.size();
        int l = 0;
        int cur = 0;
        int p = 0;
        vector<int> bits(32, 0);
        for (int r = 0; r < nums.size(); ++r) {
            p |= nums[r];
            for (int i = 0; i < 32; ++i) {
                if (nums[r] & (1<<i)) {
                    bits[i]++;
                }
            }
            cur |= nums[r];
            while(cur >= k && l <= r) {
                ans = min(ans, r - l + 1);
                for (int i = 0; i < 32; ++i) {
                    if (nums[l] & (1<<i)) {
                        bits[i]--;
                    }
                }
                ++l;
                cur = 0;
                for (int i = 0; i < 32; ++i) {
                    if (bits[i]) {
                        cur |= (1<<i);
                    }
                }
            }
        }
        return p < k ? -1 : ans;
    }
};