const int N = 3 * 1e4;

class Graph {
private:
    vector<int> adj[N];
    vector<int> ans;
    int subtreeSize[N];
    int subtreeSum[N];
    int n;
public:
    Graph(int n, vector<vector<int>> &edges) {
        this->n = n;
        initGraph(edges, n);
    }
    
    void initGraph(vector<vector<int>>& edges, int n) {
        for (int i = 0 ; i < n; ++i) {
            adj[i].clear();
        }
        ans.resize(n);
        memset(subtreeSize, 0, sizeof subtreeSize);
        memset(subtreeSum, 0, sizeof subtreeSum);
        for (auto &p : edges) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
    }
    
    int computeSubtreeSize(int child, int par = -1) {
        subtreeSize[child] = 1;
        for (auto &u : adj[child]) {
            if (u == par) {
                continue;
            }
            subtreeSize[child] += computeSubtreeSize(u, child);
        }
        return subtreeSize[child];
    }
    
    int computeSubtreeSum(int child, int par = -1) {
        subtreeSum[child] = 0;
        for (auto& u: adj[child]) {
            if (u == par) {
                continue;
            }
            subtreeSum[child] += (computeSubtreeSum(u, child) + subtreeSize[u]);
        }
        return subtreeSum[child];
    }
    
    void dfs(int child, int par = -1) {
        if (child == 0) {
            ans[0] = subtreeSum[0];
        }
        if (par != -1) {
            ans[child] = ans[par] - subtreeSize[child] + (n - subtreeSize[child]);
        }
        for (auto &u : adj[child]) {
            if (u == par) {
                continue;
            }
            dfs(u, child);
        }
    }
    
    vector<int> getAns() {
        return ans;
    }
};

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        Graph graph(n, edges);
        vector<int> ans;
        graph.computeSubtreeSize(0);
        graph.computeSubtreeSum(0);
        graph.dfs(0);
        return graph.getAns();    
    }
};
