class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        multiset<pair<int, int>> events;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // range: [n - k, n + k]
            events.insert({nums[i] - k, 1});
            events.insert({nums[i] + k + 1, -1});
        }
        int ans = -1;
        int cur = 0;
        for (auto& p : events) {
            cur += p.second;
            // cout << cur << endl;
            ans = max(ans, cur);
        }

        return ans;
    }
};