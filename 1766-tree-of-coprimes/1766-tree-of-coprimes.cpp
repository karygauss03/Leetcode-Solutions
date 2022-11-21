class Solution {
public:
    static const int N = 1e5 + 5;
    unordered_map<int, vector<int>> coprimes;
    vector<int> adj[N];
    vector<int> ans;
    unordered_map<int, vector<pair<int,int>>> anc;
    void dfs(vector<int>& nums, int node, int par, int depth){
        int mx_depth = -1;
        for (auto &cop : coprimes[nums[node]]){
            if (!anc[cop].empty() && anc[cop].back().first > mx_depth){
                mx_depth = anc[cop].back().first;
                ans[node] = anc[cop].back().second;
            }
        }
        anc[nums[node]].push_back({depth, node});
        for (auto &child : adj[node]){
            if (child != par){
                dfs(nums, child, node, depth + 1);
            }
        }
        anc[nums[node]].pop_back();
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        unordered_set<int> s(begin(nums), end(nums));
        int n = nums.size();
        for (auto &x : s){
            for (auto &y : s){
                if (__gcd(x, y) == 1){
                    coprimes[x].push_back(y);
                }
            }
        }
        for (auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        ans.resize(n, -1);
        dfs(nums, 0, 0, 0);
        return ans;
    }
};