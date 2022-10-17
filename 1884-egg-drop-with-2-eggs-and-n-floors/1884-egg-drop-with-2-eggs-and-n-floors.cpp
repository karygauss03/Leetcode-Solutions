class Solution{
public:
    int dp[3][1001];
    int solve(int e, int f){
        if (f <= 1 || e == 1)
            return f;
        if (dp[e][f] != -1)
            return dp[e][f];
        int mn = INT_MAX;
        for (int i = 1; i <= f; i++)
            mn = min(mn, 1 + max(solve(e - 1, i - 1), solve(e, f - i)));
        dp[e][f] = mn;
        return mn;
    }
    int twoEggDrop(int n){
        memset(dp, -1, sizeof(dp));
        return solve(2, n);
    }
};