typedef struct DSU
{
    vector<int> par, rank;
    DSU(int n) {
        par.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i;
        rank.resize(n, 0);
    }
    void makeSet(int v) {
        par[v] = v;
        rank[v] = 1;
    }
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    void unionSet(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (rank[u] < rank[v]) swap(u, v);
            par[v] = u;
            if (rank[u] == rank[v]) rank[u]++;
        }
    }
}DSU;

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (auto& edge: edgeList) {
            reverse(edge.begin(), edge.end());
            pq.push(edge);
        }
        int q = queries.size();
        vector<bool> ans(q);
        for (int i = 0; i < q; ++i) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        DSU dsu(n);
        for (int i = 0; i < q; ++i) {
            int u = queries[i][0], v = queries[i][1], limit = queries[i][2], j = queries[i][3];
            while (!pq.empty() && pq.top()[0] < limit) {
                vector<int> cur = pq.top();
                pq.pop();
                dsu.unionSet(cur[1], cur[2]);
            }
            ans[j] = (dsu.find(u) == dsu.find(v)) ? true : false;
        }
        return ans;
    }
};