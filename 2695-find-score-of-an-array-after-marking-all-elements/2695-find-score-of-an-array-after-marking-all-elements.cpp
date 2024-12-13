class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        set<pair<int, int>> st;
        for (int i = 0; i < n; ++i) {
            st.insert({nums[i], i});
        }

        vector<bool> marked(n, false);

        while (!st.empty()) {
            auto smallest = *st.begin();
            st.erase(st.begin());

            int val = smallest.first;
            int idx = smallest.second;

            if (marked[idx]) continue;

            ans += val;

            marked[idx] = true;
            if (idx - 1 >= 0) marked[idx - 1] = true;
            if (idx + 1 < n) marked[idx + 1] = true;

            if (idx - 1 >= 0) st.erase({nums[idx - 1], idx - 1});
            if (idx + 1 < n) st.erase({nums[idx + 1], idx + 1});
        }

        return ans;
    }
};
