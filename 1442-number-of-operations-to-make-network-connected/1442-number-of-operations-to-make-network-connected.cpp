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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        unordered_set<int> st;
        set<int> par;
        int cnt = 0;
        for (auto& cnx : connections) {
            int u = cnx[0], v = cnx[1];
            int pu = dsu.find(u), pv = dsu.find(v);
            // cout << "u: " << u << "par: " << dsu.find(u) << endl;
            // cout << "v: " << v << "par: " << dsu.find(v) << endl;
            if (pu == pv) {
                ++cnt;
                continue;
            }
            dsu.unionSet(u, v);
            st.insert(u);
            st.insert(v);
        }
        for (int i = 0; i < n; ++i) par.insert(dsu.find(i));
        // cout << "cnt: " << cnt << endl;
        cout << "par.size(): " << par.size() << endl;
        if (par.size() == 1) return 0;
        if (par.size() > 1 && cnt >= par.size() - 1) {
            return par.size() - 1;
        }
        return -1;
    }
};