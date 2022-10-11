class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        int l = nums[0], mid = INT_MAX;
        for (int i = 0 ; i < n ; i++){
            if (nums[i] > mid) return true;
            if (mid > nums[i] && nums[i] > l){
                mid = nums[i];
            }
            if (nums[i] < l){
                l = nums[i];
            }
        }
        return false;
    }
};