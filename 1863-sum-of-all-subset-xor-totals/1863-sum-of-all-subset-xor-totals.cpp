class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 1 ; i < (1<<n) ; i++){
            int cur = 0;
            for (int j = 0 ; j < nums.size() ; j++){
                if ((1<<j) & i){
                    cur ^= nums[j];
                }
            }
            ans += cur;
        }
        return ans;
    }
};