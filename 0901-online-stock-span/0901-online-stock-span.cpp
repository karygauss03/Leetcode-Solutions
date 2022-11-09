class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
    }
    
    int next(int price) {
        int ans = 1;
        while (st.size() && st.top().first <= price){
            ans += st.top().second;
            st.pop();
        }
        st.push(make_pair(price, ans));
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */