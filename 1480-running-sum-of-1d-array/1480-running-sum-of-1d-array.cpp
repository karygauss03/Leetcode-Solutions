class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        int n = nums.size();
        for (int i = 1 ; i < n ; i++){
            ans.push_back(nums[i] + ans[ans.size() - 1]);
        }
        return ans;
    }
};