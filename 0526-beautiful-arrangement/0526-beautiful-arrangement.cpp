class Solution {
public:
    int ans = 0;
    int vis = 0;
    int dfs(int n, int pos = 1){
        if (pos > n) return ans++;
        
        for (int i = 1 ; i <= n ; i++){
            int mask = (1<<i);
            if (!(vis & mask) && (i % pos == 0 || pos % i == 0)){
                vis ^= mask;
                dfs(n, pos + 1);
                vis ^= mask;
            }
        }
        
        return ans;
        
    }
    
    int countArrangement(int n) {
        if (n < 4) return n;
        return dfs(n);
    }
};