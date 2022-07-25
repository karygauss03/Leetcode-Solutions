class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int m = 0;
        while(l <= r){
            m = l+(r-l)/2;
            if(nums[m] == target){
                l = m;
                r = m;
                while(l >= 0 and nums[l] == target){l--;}
                while(r < nums.size() and nums[r] == target){r++;}
                return {l+1, r-1};
            }else if(nums[m] > target){
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return {-1, -1};
    }
};
  