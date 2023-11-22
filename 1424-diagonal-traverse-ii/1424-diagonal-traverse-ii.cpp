class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        if (nums.empty() || nums[0].empty()) {
            return {};
        }
        
        vector<int> ans;
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        while (!q.empty()) {
            pair<int, int> front = q.front();
            ans.push_back(nums[front.first][front.second]);
            if (front.first + 1 < nums.size() && front.second == 0) {
                q.push({front.first + 1, front.second});
            }
            if (front.second + 1 < nums[front.first].size()) {
                q.push({front.first, front.second + 1});
            }
            q.pop();
        }
        
        return ans;
    }
};