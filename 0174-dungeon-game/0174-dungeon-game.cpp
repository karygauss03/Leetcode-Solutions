class Solution {
public:
    int n, m;
    int dp[205][205];
    
    int calculateMinimumHP(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        memset(dp, 0, sizeof dp);
        for (int i = n - 1 ; i >= 0 ; --i) {
            for (int j = m - 1 ; j >= 0 ; --j) {
                if (i == n - 1 && j == m - 1) {
                    dp[i][j] = min(0, matrix[i][j]);
                }
                else if (i == n - 1) {
                    dp[i][j] = min(0, matrix[i][j] + dp[i][j + 1]);
                }
                else if (j == m - 1) {
                    dp[i][j] = min(0, matrix[i][j] + dp[i + 1][j]);
                }
                else {
                    dp[i][j] = min(0, matrix[i][j] + max(dp[i][j + 1], dp[i + 1][j]));
                }
            }
        }
        return abs(dp[0][0]) + 1;
    }
};