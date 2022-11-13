class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN, mn = INT_MAX, cur_mx = 0, cur_mn = 0;
        for (int i = 0 ; i < n ; i++){
            cur_mx += nums[i];
            if (cur_mx > mx){
                mx = cur_mx;
            }
            if (cur_mx < 0){
                cur_mx = 0;
            }
        }
        
        for (int i = 0 ; i < n ; i++){
            cur_mn += nums[i];
            if (cur_mn < mn){
                mn = cur_mn;
            }
            if (cur_mn > 0){
                cur_mn = 0;
            }
        }
        return max(abs(mx), abs(mn));
    }
};