class Solution {
private:
    unordered_map<string, multiset<string>> adj;
    vector<string> ans;
    void dfs(string node) {
        while(!adj[node].empty()) {
            string cur = *adj[node].begin();
            adj[node].erase(adj[node].begin());
            dfs(cur);
        }
        ans.push_back(node);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket: tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};