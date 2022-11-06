class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for (int i = 0 ; i < nums.size() ; i++){
            max_or |= nums[i];
        }
        int ans = 0;
        for (int i = 1 ; i < (1<<nums.size()) ; i++){
            int cur_or = 0;
            for (int j = 0 ; j < nums.size() ; j++){
                if ((1<<j) & i){
                    cur_or |= nums[j];
                }
            }
            if (cur_or == max_or){
                ans++;
            }
        }
        return ans;
    }
};