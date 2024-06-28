class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> adj[n + 5];
        for (auto &road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        priority_queue<int> pq;
        for (int i = 0; i < n; ++i) {
            pq.push(adj[i].size());
        }

        long long ans = 0;
        int cur = n;
        while (!pq.empty() && cur) {
           ans += ((1LL)*pq.top() * (1LL)*cur);
            --cur;
            pq.pop();
        }
        return ans;
    }
};