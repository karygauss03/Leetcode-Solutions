class Solution {
public:
    int countOrders(int n) {
        uint64_t v = fact(n*2);
        return fact(n*2);
    }
    
    uint64_t fact(uint64_t n) {
        if(n == 2) return 1;
        return ((n >> !(n & 1)) * fact (n-1)) % m;
    }
    
    const uint64_t m = 1e9 + 7;
};