class Solution {
public:
    const static int MOD = 1e9 + 7;
    int dp[100005][2][3];
    
    int solve(int n, int days, int abs, int late) {
        if (days == n) {
            return 1;
        }
        if (dp[days][abs][late] != -1) {
            return dp[days][abs][late];
        }
        long long ans = 0;
        ans += (solve(n, days + 1, abs, 0));
        if (abs < 1){
            ans += (solve(n, days + 1, abs + 1, 0));
        }
        if (late < 2) {
            ans += (solve(n, days + 1, abs, late + 1));
        }
        return dp[days][abs][late] =  ans % MOD;
    }
    int checkRecord(int n) {
        memset(dp, -1, sizeof dp);
        return solve(n, 0, 0, 0);
    }
};