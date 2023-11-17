class Solution { 
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1;
        int maxPairSum = INT_MIN;

        while (left < right) {
            int pairSum = nums[left] + nums[right];
            maxPairSum = max(maxPairSum, pairSum);
            left++;
            right--;
        }

        return maxPairSum;
        
    }
};