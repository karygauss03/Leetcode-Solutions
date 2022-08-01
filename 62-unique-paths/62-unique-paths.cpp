class Solution {
public:
    int dp[105][105];
    
    int solve(int n, int m){
        if (n == 0 && m == 0) return 1;
        if (n < 0 || m < 0) return 0;
        int &res = dp[n][m];
        if (res != -1) return res;
        int left = solve(n, m - 1), top = solve(n - 1, m);
        return res = left + top;
    }
    
    int uniquePaths(int n, int m) {
        if (n == 1 && m == 1) return 1;
        memset(dp, -1, sizeof dp);
        
        return solve(n - 1, m - 1);
    }
};