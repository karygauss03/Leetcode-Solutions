class Solution {
private:
    void dfs(int u){
        if (vis[u]) return;
        vis[u] = true;
        for (auto &v : adj[u]){
            dfs(v);
        }
    }
public:
    vector<int> adj[(int)1e5 + 1];
    int cnt = 0;
    bool vis[(int)1e5 + 1];
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        for (int i = 0 ; i < n ; i++){
            adj[i].clear();
        }
        for (auto &p : connections){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        memset(vis, 0, sizeof vis);
        for (int i = 0 ; i < n ; i++){
            if (!vis[i]){
                dfs(i);
                cnt++;
            }
        }
        return cnt - 1;
    }
};