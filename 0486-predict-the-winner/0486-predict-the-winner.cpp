class Solution {
private:
    int dp[25][25];
public:
    
    int solve(vector<int>& nums, int i, int j, int turn) {
        if (i > j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int takeFirst = 0, takeLast = 0, ans = 0;
        if (!turn) {
            takeFirst = nums[i] + solve(nums, i + 1, j, turn ^ 1);
            takeLast =  nums[j] + solve(nums, i, j - 1, turn ^ 1);
            ans = max(takeFirst, takeLast);
        }
        else {
            takeFirst = -nums[i] + solve(nums, i + 1, j, turn ^ 1);
            takeLast = -nums[j] + solve(nums, i, j - 1, turn ^ 1);
            ans = min(takeFirst, takeLast);
        }
        return dp[i][j] = ans;
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return solve(nums, 0, nums.size() - 1, 0) >= 0;
    }
};