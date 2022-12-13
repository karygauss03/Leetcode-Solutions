class Solution {
public:
    int n;
    int dp[105][105];
    int solve(int row, int col, vector<vector<int>>& matrix) {
        if (row < 0 || col < 0 || row >= n || col >= n) return 9999999;
        if (dp[row][col] != -1) return dp[row][col];
        if (row == n - 1){
            return matrix[row][col];
        }
        return dp[row][col] = matrix[row][col] + min(solve(row + 1, col, matrix), min(solve(row + 1, col + 1, matrix), solve(row + 1, col - 1, matrix)));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        memset(dp, -1, sizeof dp);
        int ans = INT_MAX;
        for (int col = 0 ; col < n ; col++){
            ans = min(ans, solve(0, col, matrix));
        }
        return ans;
    }
};