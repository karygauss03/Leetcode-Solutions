class Solution {
public:
    int dp[205][205];
    int m, n;
    int solve(vector<vector<int>>& matrix, int prev, int i, int j){
        if (i >= n || i < 0 || j >= m || j < 0) return 0;
        if (matrix[i][j] <= prev) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = 1 + max(
            max(solve(matrix, matrix[i][j], i + 1, j), solve(matrix, matrix[i][j], i - 1, j)),
            max(solve(matrix, matrix[i][j], i, j + 1), solve(matrix, matrix[i][j], i, j - 1))
        );
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        memset(dp, -1, sizeof dp);
        int ans = INT_MIN;
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                ans = max(ans, solve(matrix, -1, i, j));
            }
        }
        return ans;
    }
};