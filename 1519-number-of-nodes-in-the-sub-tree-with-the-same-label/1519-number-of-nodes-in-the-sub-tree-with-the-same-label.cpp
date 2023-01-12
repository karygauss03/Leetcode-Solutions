class Solution {
public:
    // int N = 1e5 + 5;
    vector<int> adj[(int)1e5 + 5];
    bool vis[(int)1e5 + 5];
    vector<int> ans;
    
    void dfs(int u, string& labels, map<char, int>& freq, int par = -1) {
        if (vis[u]) return;
        vis[u] = true;
        int prevCount = freq[labels[u] - 'a'];
        freq[labels[u] - 'a']++;
        
        for (auto v: adj[u]) {
            if (v == u) continue;
            dfs(v, labels, freq, u);
            freq[labels[v]]++;
        }
        ans[u] += freq[labels[u] - 'a'] - prevCount;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        for (int i = 0 ; i < edges.size() + 1 ; i++) {
            adj[i].clear();
        }
        for (int i = 0 ; i < edges.size() ; i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(vis, false, sizeof vis);
        ans.resize(edges.size() + 1);
        map<char, int> freq;
        dfs(0, labels, freq);
        return ans;
    }
};