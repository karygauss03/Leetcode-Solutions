class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        int n = nums.size();
        vector<pair<int, int>> ranges;
        int l = 0, r;
        for (r = 1; r < n; ++r) {
            if (nums[r] % 2 == nums[r - 1] % 2) {
                ranges.push_back({l, r - 1});
                l = r;
            }
        }
        ranges.push_back({l, n - 1});
        // for (auto& r : ranges) {
        //     cout << r.first << " " << r.second << endl;
        // }
        for (auto &q : queries) {
            auto it = lower_bound(ranges.begin(), ranges.end(), make_pair(q[0], 0),
                [](const pair<int, int>& range, const pair<int, int>& key) {
                    return range.second < key.first;
                });
            if (it == ranges.end()) {
                ans.push_back(false);
                continue;
            }
            int end = q[1];
            if (end <= it->second && end >= it->first) {
                ans.push_back(true);
                continue;
            }
            ans.push_back(false);
        }
        return ans;
    }
};