class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> leftSum;
        int ans = INT_MAX;
        
        for (int i = 0, currentSum = 0; i <= nums.size() && currentSum <= x; ++i) {
            leftSum[currentSum] = i;
            if (i < nums.size()) {
                currentSum += nums[i];
            }
        }
        
        for (int i = nums.size() - 1 , currentSum = 0; i >= 0 && currentSum <= x; --i) {
            auto left = leftSum.find(x - currentSum);
            if (left != leftSum.end() && i + 1 >= left->second) {
                ans = min(ans, (int)nums.size() - i - 1 + left->second);
            }
            currentSum += nums[i];
        }
        return ans != INT_MAX ? ans : -1;
    }
};