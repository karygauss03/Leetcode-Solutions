class Graph{
private:
    int n;
    int k;
    vector<int> values;
    vector<vector<int>> adj;
    vector<bool> vis;
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
public:
    Graph(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->n = n;
        this->k = k;
        this->values = values;
        adj.resize(n);
        for (auto& e : edges) {
            addEdge(e[0], e[1]);
        }
        vis.resize(n, false);
    }
    
    int dfs(int node, long long& sum) {
        if (vis[node]) return 0;
        vis[node] = true;
        sum += (long long)values[node];
        int cnt = 0;
        for (auto& v : adj[node]) {
            if (!vis[v]) {
                long long curSum = 0;
                cnt += dfs(v, curSum);
                if (curSum % k == 0) {
                    ++cnt;
                }
                else {
                    sum += curSum;
                }
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        Graph graph = Graph(n, edges, values, k);
        long long sum = 0;
        int ans = graph.dfs(0, sum);
        if (sum % k == 0) ++ans;
        return ans;
    }
};