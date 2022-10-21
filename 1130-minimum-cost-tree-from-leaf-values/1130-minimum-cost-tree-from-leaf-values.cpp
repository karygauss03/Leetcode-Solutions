class Solution {
private:
    int n;
    int solve(int i, int j, const vector<int> &arr, vector<vector<int>> &dp, const vector<vector<int>> &mx) {
        if (i == j) return 0;
        if (i + 1 == j){
            dp[i][j] = arr[i] * arr[j];
            return dp[i][j];
        }
        if (dp[i][j] != INT_MAX) return dp[i][j];
        for (int k = i ; k < j ; k++){
            int tmp = solve(i, k, arr, dp, mx) + solve(k + 1, j, arr, dp, mx) + mx[i][k] * mx[k + 1][j];
            dp[i][j] = min(dp[i][j], tmp);
        }
        return dp[i][j];
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n,INT_MAX));
        vector<vector<int>> mx(45, vector<int>(45, 0));
        for (int i = 0 ; i < n ; i++){
            mx[i][i] = arr[i];
            for (int j = i + 1 ; j < n ; j++){
                mx[i][j] = max(mx[i][j - 1], arr[j]);
            }
        }
        return solve(0, n - 1, arr, dp, mx);
    }
};