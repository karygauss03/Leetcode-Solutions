class Solution {
public:
    int dp[105][105][3];
    int pref[205];
    
    int query(int l, int r){
        if(l == 0) return pref[r];
        return pref[r] - pref[l - 1];
    }
    
    int solve(vector<int>& piles, int i, int m, int player){
        if (i >= piles.size()) return 0;
        if (dp[i][m][player] != -1) return dp[i][m][player];
        
        if (player == 1){
            int ans = 0;
            for (int j = 0 ; j < 2*m ; j++){
                ans = max(ans, query(i, i + j) + solve(piles, i + j + 1, max(m, j + 1), 2));
            }
            return dp[i][m][player] = ans;
        }
        else {
            int ans = INT_MAX;
            for (int j = 0 ; j < 2*m ; j++){
                ans = min(ans, solve(piles, j + i + 1, max(m, j + 1), 1));
            }
            if (ans == INT_MAX) ans = 0;
            return dp[i][m][player] = ans;
        }
    }
    
    int stoneGameII(vector<int>& piles) {
        if (piles.size() == 1) return piles[0];
        if (piles.size() == 0) return 0;
        pref[0] = piles[0];
        for (int i = 1 ; i < piles.size() ; i++){
            pref[i] = pref[i - 1] + piles[i];
        }
        memset(dp, -1, sizeof dp);
        return solve(piles, 0, 1, 1);
    }
};