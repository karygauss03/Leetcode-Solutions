class Solution {
public:
    vector<int> adj_row[10005], adj_col[10005];
    unordered_set<int> vis;
    int dfs (int &s, vector<vector<int>> &stones){
        if (vis.count(s)) return 0;
        vis.insert(s);
        int r = stones[s][0], c = stones[s][1];
        for (auto &u : adj_row[r]) dfs(u, stones);
        for (auto &u : adj_col[c]) dfs(u, stones);
        return 1;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        for (int i = 0 ; i < 10005 ; i++){
            adj_row[i].clear(), adj_col[i].clear();    
        }
        for (int i = 0 ; i < n ; i++){
            adj_row[stones[i][0]].push_back(i);
            adj_col[stones[i][1]].push_back(i);
        }
        int ans = 0;
        for (int i = 0 ; i < n ; i++){
            ans += dfs(i, stones);
        }
        return n - ans;
    }
};