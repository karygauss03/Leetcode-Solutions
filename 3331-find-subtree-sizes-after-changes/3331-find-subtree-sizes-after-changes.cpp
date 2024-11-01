class Graph {
public:
    const static int N = (1e5) + 5;
    vector<int> adj[N];
    vector<int> new_adj[N];
    bool vis[N];
    map<char, vector<int>> seen; 
    string s;
    vector<int> ans;

    Graph(vector<int>& par, string t) {
        int n = par.size();
        ans.resize(n, 1);
        s = t;

        for (int i = 1; i < n; ++i) {
            adj[par[i]].push_back(i);
            adj[i].push_back(par[i]);
        }
        memset(vis, false, sizeof vis);
    }

    void dfs_build(int node, int par = -1) {
        if (vis[node]) return;
        
        vis[node] = true;
        char c = s[node];
        
        int closestAncestor = -1;
        if (seen.find(c) != seen.end() && !seen[c].empty()) {
            closestAncestor = seen[c].back();
        }

        if (closestAncestor != -1 && closestAncestor != par) {
            new_adj[closestAncestor].push_back(node);
        } else if (par != -1) {
            new_adj[par].push_back(node);
        }

        seen[c].push_back(node);

        for (auto& v : adj[node]) {
            if (v != par) {
                dfs_build(v, node);
            }
        }

        seen[c].pop_back();
    }

    void dfs_calculate_sizes(int node) {
        for (auto& v : new_adj[node]) {
            dfs_calculate_sizes(v);
            ans[node] += ans[v];
        }
    }
};

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        Graph graph(parent, s);

        graph.dfs_build(0);
        
        memset(graph.vis, false, sizeof graph.vis);

        graph.dfs_calculate_sizes(0);
        
        return graph.ans;
    }
};
