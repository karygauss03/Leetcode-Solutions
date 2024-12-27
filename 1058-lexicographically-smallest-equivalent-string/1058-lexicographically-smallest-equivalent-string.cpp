typedef struct DSU
{
    vector<int> par, rank;
    DSU(int n) {
        par.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i;
        rank.resize(n, 0);
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unionSet(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (u > v) swap(u, v);
            par[v] = u;
            if (rank[u] == rank[v]) rank[u]++;
        }
    }
} DSU;

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size(), m = baseStr.size();
        DSU dsu(26);
        for (int i = 0; i < n; ++i) {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            dsu.unionSet(u, v);
        }
        string ans = "";
        for (int i = 0; i < m; ++i) {
            int c = baseStr[i] - 'a';
            int par = dsu.find(c);
            ans += par + 'a';
        }
        return ans;
    }
};