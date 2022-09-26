class Solution {
public:
    map<char, vector<char>> adj;
    map<char, bool> vis;
    vector<pair<int, int>> invalid;
    bool dfs(int u, int v){
        if (!vis[u]){
            vis[u] = true;
            for (auto &x : adj[u]){
                if (x == v) return false;
                if (dfs(x, v) == false) return false;
            }
        }
        return true;
    }
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        for (int i = 0 ; i < n ; i++){
            if (equations[i][1] == '!'){
                if (equations[i][0] == equations[i][3]){
                    return false;
                }
                invalid.push_back({equations[i][0], equations[i][3]});
            }
            else {
                adj[equations[i][0]].push_back(equations[i][3]);
                adj[equations[i][3]].push_back(equations[i][0]);
            }
        }
        
        for (auto &p : invalid){
            vis.clear();
            if (dfs(p.first, p.second) == false) return false;
        }
        return true;
    }
};