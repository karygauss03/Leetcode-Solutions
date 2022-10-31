class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, temp, target, 0, res);
        return res;
    }

    void solve(vector<int>& can, vector<int>& temp, int target, int idx, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }

        for (int i = idx; i < can.size(); i++) {
            if (i > 0 && can[i] == can[i-1] && i > idx) continue;
            if(can[i]>target) break;
            temp.push_back(can[i]);
            solve(can, temp, target - can[i], i + 1, res);
            temp.pop_back();
        }
    }
};