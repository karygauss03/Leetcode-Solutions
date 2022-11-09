class StockSpanner {
public:
    vector<int> a;
    StockSpanner() {
    }
    
    int next(int price) {
        int ans = 1;
        int tmp = price;
        for (int i = a.size() - 1 ; i >= 0 ; i--){
            if (a[i] <= tmp){
                ans++;
            }
            else break;
        }
        a.push_back(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */