class Solution {
public:
    bool vis[10005];
    vector<pair<int, double>> adj[10005];
    double ans = 0.0;
    
    void dfs(int node, int end, double cur) {
        if (cur <= 1e-5) return;
        if (node == end) {
            ans = max(ans, cur);
            return;
        }
        vis[node] = 1;
        for (auto &u : adj[node]){
            if (!vis[u.first] && cur * u.second >= ans) {
                dfs(u.first, end, cur * u.second);
            }
        }
        vis[node] = 0;
    } 
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        memset(vis, 0, sizeof vis);
        for (int i = 0 ; i < edges.size() ; ++i) {
            adj[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        dfs(start, end, 1);
        return ans;
    }
};