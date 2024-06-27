class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
       vector<int> adj[edges.size() + 5];
        for (auto &edge : edges) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
            if (adj[edge[0] - 1].size() == min(3, (int)edges.size())) {
                return edge[0];
            }
            adj[edge[1] - 1].push_back(edge[0] - 1);
            if (adj[edge[1] - 1].size() == min(3, (int)edges.size())) {
                    return edge[1];
            }
        }
        return -1;
    }
};