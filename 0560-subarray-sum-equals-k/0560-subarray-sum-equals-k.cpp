class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> sumFreq;
        sumFreq[0] = 1; // Empty sub-array
        int sum = 0, ans = 0;
        for (auto & num : nums) {
            sum += num;
            if (sumFreq.find(sum - k) != sumFreq.end()) {
                ans += sumFreq[sum - k];
            }
            sumFreq[sum]++;
        }
        return ans;
    }
};