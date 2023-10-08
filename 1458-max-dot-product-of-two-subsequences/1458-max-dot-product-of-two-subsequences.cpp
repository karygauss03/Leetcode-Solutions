class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if (m < n) {
            return maxDotProduct(nums2, nums1);
        }

        vector<long> dp(n + 1, INT_MIN);

        for (int i = 0; i < m; i++) {
            long prev = 0;
            for (int j = 0; j < n; j++) {
                long tmp = dp[j + 1];
                dp[j + 1] = max(prev + (long)nums1[i] * nums2[j], max((long)nums1[i] * nums2[j], max(dp[j], dp[j + 1])));
                prev = tmp;
            }
        }

        return (int)dp[n];
    }
};