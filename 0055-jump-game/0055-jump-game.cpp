class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur; //maximum element can be reached a moment
        cur = nums[0];// at first the maximum element we can reach is nums[0]
        for (int i = 0 ; i < nums.size() ; i++){
            if (cur < i){
                return false;
            }
            cur = max(i + nums[i], cur);
        }
        return true;
    }
};