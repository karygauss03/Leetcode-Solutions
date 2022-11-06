class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0 ; i < (1<<n) ; i++){
            vector<int> cur;
            for (int j = 0 ; j < n ; j++){
                if ((1<<j) & i){
                    cur.push_back(nums[j]);
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};