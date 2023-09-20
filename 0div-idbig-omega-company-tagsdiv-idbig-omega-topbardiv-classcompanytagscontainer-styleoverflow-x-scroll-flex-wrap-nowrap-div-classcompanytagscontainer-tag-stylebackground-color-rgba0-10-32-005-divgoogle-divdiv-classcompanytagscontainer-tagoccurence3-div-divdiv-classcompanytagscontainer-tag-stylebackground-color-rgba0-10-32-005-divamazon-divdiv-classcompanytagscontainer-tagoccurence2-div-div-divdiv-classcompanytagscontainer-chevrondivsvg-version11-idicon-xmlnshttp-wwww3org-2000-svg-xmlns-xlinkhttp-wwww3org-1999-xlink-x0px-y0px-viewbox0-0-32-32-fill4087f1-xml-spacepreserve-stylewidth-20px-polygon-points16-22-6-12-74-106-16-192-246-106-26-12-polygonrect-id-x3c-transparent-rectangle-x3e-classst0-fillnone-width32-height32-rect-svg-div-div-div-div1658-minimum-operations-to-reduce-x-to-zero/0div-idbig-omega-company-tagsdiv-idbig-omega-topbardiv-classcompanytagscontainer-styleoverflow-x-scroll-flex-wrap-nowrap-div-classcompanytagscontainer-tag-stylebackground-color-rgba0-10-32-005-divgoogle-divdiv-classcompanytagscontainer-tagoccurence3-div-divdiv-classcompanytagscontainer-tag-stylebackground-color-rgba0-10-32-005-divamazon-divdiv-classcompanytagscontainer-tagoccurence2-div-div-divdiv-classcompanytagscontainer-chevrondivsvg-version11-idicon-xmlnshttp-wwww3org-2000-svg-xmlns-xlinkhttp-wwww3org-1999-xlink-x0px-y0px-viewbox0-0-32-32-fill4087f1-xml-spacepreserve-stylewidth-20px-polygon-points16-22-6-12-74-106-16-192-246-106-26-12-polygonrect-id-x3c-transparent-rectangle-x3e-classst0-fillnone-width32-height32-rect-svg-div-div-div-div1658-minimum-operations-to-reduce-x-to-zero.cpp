class Solution {
public:
    unordered_map<int, int> prefixSum;
    int curSum = 0;
    int minOperations(vector<int>& nums, int x) {
        for (int i = 0 ; i < nums.size() ; ++i) {
            curSum += nums[i];
            prefixSum[curSum] = i;
        }
        if (x > curSum) {
            return -1;
        }
        prefixSum[0] = 0;
        int longestLength = 0, target = curSum - x;
        curSum = 0;
        for (int i = 0 ; i < nums.size() ; ++i) {
            curSum += nums[i];
            if (prefixSum.count(curSum - target)) {
                if (curSum - target == 0) {
                    longestLength = max(longestLength, i - prefixSum[curSum - target] + 1);
                }
                else {
                    longestLength = max(longestLength, i - prefixSum[curSum - target]);
                }
            }
        }
        return longestLength == 0 ? (target == 0 ? nums.size() : -1) : nums.size() - longestLength;
    }
};