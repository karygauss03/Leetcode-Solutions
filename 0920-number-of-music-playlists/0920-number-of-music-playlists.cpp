class Solution {
public:
    static const int mod = 1e9+7;
    int dp[101][101];
    int solve (int idx, int goal, int k, int n){
        if(goal <= 0 && idx <= 0) return 1;
        else if(goal <= 0 || idx <= 0) return 0;
        if(dp[idx][goal] != -1) return dp[idx][goal];
        long long ans = 0;
        long long val = ((long long)solve(idx - 1, goal - 1, k, n) * (n - idx + 1)) % mod;
        ans = (ans + val) % mod;
        val = ((long long)solve(idx, goal - 1, k, n) * max(0, idx - k)) % mod;
        ans = (ans + val) % mod;
        return dp[idx][goal] = ans;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(n, goal, k, n);
    }
};