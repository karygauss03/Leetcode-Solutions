class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int secondXor = 0;
        for (auto &x : nums2) {
            secondXor ^= x;
        }
        int ans = 0;
        for (auto &x : nums1) {
            if (m & 1) ans ^= x;
            ans ^= secondXor;
        }
        return ans;
    }
};