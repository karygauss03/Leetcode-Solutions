class Solution {
private:
    int MOD = 1e9 + 7;
    int solve(int i, int l, int h, int z, int o, vector<int>& dp) {
        if (i > h) return 0;
        if (dp[i] != -1) return dp[i];
        int cur = 0;
        if (i >= l && i <= h) ++cur;
        cur += solve(i + z, l, h, z, o, dp);
        cur = (cur % MOD + solve(i + o, l, h, z, o, dp) % MOD) % MOD;
        return dp[i] = cur % MOD;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return solve(0, low, high, zero, one, dp);
    }
};