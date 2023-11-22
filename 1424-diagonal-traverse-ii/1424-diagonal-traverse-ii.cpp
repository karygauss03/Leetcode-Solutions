class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> valuesBySum;
        for (int i = 0 ; i < nums.size() ; ++i) {
            for (int j = 0 ; j < nums[i].size() ; ++j) {
                valuesBySum[i + j].push_back(nums[i][j]);
                
            }
        }
        vector<int> ans;
        for (auto &m : valuesBySum) {
            int sum = 0;
            for (int i = m.second.size() - 1 ; i >= 0 ; --i) {
                ans.push_back(m.second[i]);
            }
        }
        return ans;
    }
};