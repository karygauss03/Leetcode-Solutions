struct segtree {
    vector<long long> sums;
    int size;
    
    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(size * 2, 0LL);
    }
    
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);
        sums[x] = max(sums[2 * x + 1], sums[2 * x + 2]);
    }
    
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
    
    long long sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return sums[x];
        int m = (lx + rx) / 2;
        return max(sum(l, r, 2 * x + 1, lx, m), sum(l, r, 2 * x + 2, m, rx));
    }
    
    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

class StockSpanner {
public:
    int mxN = 1e5;
    int p = 1;
    segtree st;
    
    StockSpanner() { 
        st.init(mxN);
    }
    
    int next(int price) {
        st.set(price, p);
        return p++ - st.sum(price + 1, mxN);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */