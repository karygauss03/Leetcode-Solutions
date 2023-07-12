class Solution {
public:
    vector<int> ans;
    vector<int> col;
    
    bool dfs(vector<vector<int>> &adj, int node) {
        if (col[node] > 0) {
            return col[node] == 2;
        }
        col[node] = 1;
        for (auto u : adj[node]) {
            if (col[u] == 1 || !dfs(adj, u)) {
                return false;
            }
        }
        col[node] = 2;
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        col.resize(10005, 0);
        for (int i = 0; i < n ; ++i) {
            if (dfs(graph, i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};