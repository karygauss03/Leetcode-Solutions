class Solution {
public:
    int dp[30][6000];
    int solve(vector<int>& stones, int sum = 0, int i = 0){
        if (i == stones.size()) return sum < 0 ? 100 : sum;
        if (dp[i][sum + 3000] == 0){
            dp[i][sum + 3000] = 1 + min(solve(stones, sum + stones[i], i + 1), solve(stones, sum - stones[i], i + 1));
        }
        return dp[i][sum + 3000] - 1;
    }
    int lastStoneWeightII(vector<int>& stones) {
        return solve(stones, 0, 0);
    }
};