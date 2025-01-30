class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> parent(n, -1);
        vector<int> depth(n, 0);

        for (auto& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
            unite(u, v, parent, depth);
        }

        unordered_map<int, int> maxGroups;

        for (int node = 0; node < n; ++node) {
            int groups = calculateGroups(graph, node, n);
            if (groups == -1) return -1;
            int root = findRoot(node, parent);
            maxGroups[root] = max(maxGroups[root], groups);
        }

        int totalGroups = 0;
        for (auto& [root, groups] : maxGroups) {
            totalGroups += groups;
        }

        return totalGroups;
    }

private:
    int findRoot(int node, vector<int>& parent) {
        while (parent[node] != -1) node = parent[node];
        return node;
    }

    void unite(int u, int v, vector<int>& parent, vector<int>& depth) {
        u = findRoot(u, parent);
        v = findRoot(v, parent);

        if (u == v) return;

        if (depth[u] < depth[v]) swap(u, v);
        parent[v] = u;

        if (depth[u] == depth[v]) depth[u]++;
    }

    int calculateGroups(vector<vector<int>>& graph, int start, int n) {
        queue<int> q;
        vector<int> layer(n, -1);
        q.push(start);
        layer[start] = 0;
        int maxLayer = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int current = q.front();
                q.pop();
                for (int neighbor : graph[current]) {
                    if (layer[neighbor] == -1) {
                        layer[neighbor] = maxLayer + 1;
                        q.push(neighbor);
                    } else if (layer[neighbor] == maxLayer) {
                        return -1;
                    }
                }
            }
            maxLayer++;
        }

        return maxLayer;
    }
};