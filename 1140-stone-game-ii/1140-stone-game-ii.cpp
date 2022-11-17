class Solution {
public:
    int dp[105][105];
    int suff[105];

    int solve(vector<int>& piles, int i, int m){
        if (i == piles.size()) return 0;
        if (2 * m >= piles.size() - i) return suff[i];
        if (dp[i][m] != -1) return dp[i][m];
        int mn = INT_MAX;
        for (int j = 1 ; j <= 2 * m ; j++){
            mn = min(mn, solve(piles, i + j, max(j, m)));
        }
        return dp[i][m] = suff[i] - mn;
    }
    
    int stoneGameII(vector<int>& piles) {
        if (piles.size() == 1) return piles[0];
        if (piles.size() == 0) return 0;
        suff[piles.size() - 1] = piles[piles.size() - 1];
        for (int i = piles.size() - 2 ; i >= 0 ; i--){
            suff[i] = suff[i + 1] + piles[i];
        }
        memset(dp, -1, sizeof dp);
        solve(piles, 0, 1);
        return dp[0][1];
    }
};