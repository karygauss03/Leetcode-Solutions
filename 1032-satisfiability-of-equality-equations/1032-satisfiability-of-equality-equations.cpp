typedef struct DSU
{
    vector<int> par, rank;
    DSU(int n) {
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            makeSet(i);
        }
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
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);
        for (auto& eq : equations) { 
            if (eq[1] == '=') { 
                int u = eq[0] - 'a', v = eq[3] - 'a'; 
                dsu.unionSet(u, v); 
            } 
        }
        for (auto& eq : equations) { 
            if (eq[1] == '!') { 
                int u = eq[0] - 'a', v = eq[3] - 'a'; 
                if (dsu.find(u) == dsu.find(v)) { 
                    return false; 
                }
            }
        }
        return true;
    }
};