class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int curMax = nums[0], curMin = nums[0];
        
        for (int i = 1 ; i < n ; i++){
            if (nums[i] < 0){
                swap(curMax, curMin);
            }
            curMax = max(curMax * nums[i], nums[i]);
            curMin = min(curMin * nums[i], nums[i]);
            ans = max(curMax, ans);
        }
        return ans;
    }
};