class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<vector<int>> res;
        
        for (int i = 0 ; i < (1<<n) ; i++){
            vector<int> tmp, sorted;
            for (int j = 0 ; j < n ; j++){
                if((i & (1<<j)) != 0){
                    tmp.push_back(nums[j]);
                }
            }
            sorted = tmp;
            sort(sorted.begin(), sorted.end());
            if (find(ans.begin(), ans.end(), tmp) == ans.end() && find(res.begin(), res.end(), sorted) == res.end()){
                ans.push_back(tmp);
                res.push_back(sorted);
            } 
        }
        return ans;
    }
};