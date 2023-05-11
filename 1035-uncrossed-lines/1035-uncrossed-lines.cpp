class Solution {
  public: int c(vector < int > & v1, vector < int > & v2, int i, int j, vector < vector < int >> & dp) {
    if (i >= v1.size() || j >= v2.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if (v1[i] == v2[j]) {
      ans = 1 + c(v1, v2, i + 1, j + 1, dp);
    }
    ans = max({
      ans,
      c(v1, v2, i + 1, j, dp),
      c(v1, v2, i, j + 1, dp)
    });
    dp[i][j] = ans;
    return ans;
  }
  int maxUncrossedLines(vector < int > & v1, vector < int > & v2) {
    vector < vector < int >> dp(v1.size(), vector < int > (v2.size(), -1));
    return c(v1, v2, 0, 0, dp);
  }
};