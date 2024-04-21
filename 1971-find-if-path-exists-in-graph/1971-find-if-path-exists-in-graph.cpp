class Solution {
public:
    bool vis[200005];
    vector<int> adj[200005];
    void dfs(int s){
        if (vis[s]) return;
        vis[s] = true;
        for (auto &x : adj[s]){
            dfs(x);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for (int i = 0 ; i < n ; i++) vis[i] = false;
        for (int i = 0 ; i < n ; i++) adj[i].clear();
        
        for (auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        dfs(source);
        if (!vis[destination]) return false;
        return true;
    }
};