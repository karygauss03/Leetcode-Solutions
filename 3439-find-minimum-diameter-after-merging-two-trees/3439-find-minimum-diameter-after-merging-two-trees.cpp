class Tree {
private:
    int n;
    vector<vector<int>> adj;
public:
    Tree(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(n);
        for (auto& p : edges) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
    }

    pair<int, int> FindFarthestNode(int start) {
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(start);
        vis[start] = true;
        int farthestNode = start;
        int mx = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int cur = q.front();
                q.pop();
                farthestNode = cur;
                for (auto& u : adj[cur]) {
                    if (!vis[u]) {
                        vis[u] = true;
                        q.push(u);
                    }
                }
            }
            if (!q.empty()) {
                ++mx;
            }
        }
        return {farthestNode, mx};
    }

    int GetDiameter() {
        pair<int, int> p = FindFarthestNode(0);
        pair<int, int> u = FindFarthestNode(p.first);
        return u.second;
    }
};
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        Tree t1(edges1.size() + 1, edges1);
        Tree t2(edges2.size() + 1, edges2);
        int d1 = t1.GetDiameter(), d2 = t2.GetDiameter();
        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};