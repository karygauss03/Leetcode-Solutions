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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DSU dsu(n);
        for (auto& p : pairs) {
            int u = p[0], v = p[1];
            dsu.unionSet(u, v);
        }
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            int par = dsu.find(i);
            mp[par].push_back(i);
        }
        for (auto& m : mp) {
            vector<int> idx = m.second;
            string c;
            for (auto& i : idx) {
                c.push_back(s[i]);
            }
            sort(c.begin(), c.end());
            sort(idx.begin(), idx.end());
            for (int i = 0; i < idx.size(); ++i) {
                s[idx[i]] = c[i];
            }
        }
        return s;
    }
};