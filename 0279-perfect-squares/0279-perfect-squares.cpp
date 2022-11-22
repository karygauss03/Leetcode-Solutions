class Solution {
public:
    int dp[10005];
    vector<int> sq;
    int solve(int cur){
        if (!cur) return 0;
        if (dp[cur] != -1) return dp[cur];
        int cur_min = INT_MAX;
        for (auto& x : sq){
            if (cur - x < 0) continue;
            cur_min = min(cur_min, 1 + solve(cur - x));
        }
        return dp[cur] = cur_min;
    }
    int numSquares(int n) {
        for (int i = 1 ; i * i <= n ; i++){
            sq.push_back(i * i);
        }
        memset(dp, -1, sizeof dp);
        return solve(n);
    }
};