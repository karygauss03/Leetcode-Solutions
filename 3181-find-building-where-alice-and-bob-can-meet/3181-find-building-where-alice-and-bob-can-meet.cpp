class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), q = queries.size(), i = 0;
        map<int, vector<pair<int,int>>> mp;
        vector<int> ans(q, -1);
        for (int i = 0; i < q; ++i) {
            int l = min(queries[i][0], queries[i][1]);
            int r = max(queries[i][0], queries[i][1]);
            if (l == r || heights[r] > heights[l]) {
                ans[i] = r;
                continue;
            }
            mp[r].push_back({max(heights[l], heights[r]), i});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; ++i) {
            for (auto& p : mp[i]) {
                pq.push(p);
            }
            while (!pq.empty() && heights[i] > pq.top().first) {
                // cout << i << " " << pq.top().first << " " << pq.top().second << endl;
                ans[pq.top().second] = i;
                pq.pop();
            }
        }
        return ans;
    }
};