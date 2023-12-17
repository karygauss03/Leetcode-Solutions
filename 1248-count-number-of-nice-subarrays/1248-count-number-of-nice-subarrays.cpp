class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for (int &num : nums) {
            num %= 2;
        }
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefixSum = 0, ans = 0;
        for (int i = 0; i < nums.size() ; ++i) {
            prefixSum += nums[i];
            if (mp.find(prefixSum - k) != mp.end()) {
                ans += mp[prefixSum - k];
            }
            mp[prefixSum]++;
        }
        return ans;
    }
};