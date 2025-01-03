class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans = -(1LL<<62);
        unordered_map<int, long long> prefix;
        prefix[k - 1] = 0;
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (prefix.find(i % k) != prefix.end()) {
                ans = max(ans, sum - prefix[i % k]);
                prefix[i % k] = min(sum, prefix[i % k]);
            }
            else {
                prefix[i % k] = sum;
            }
        }
        return ans;
    }
};