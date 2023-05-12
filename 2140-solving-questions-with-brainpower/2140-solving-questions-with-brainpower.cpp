class Solution {
  public: long long solve(int i, vector < vector < int >> & q, vector < long long > & dp) {
    if (i >= q.size()) return 0;
    long long ans = 0;
    if (dp[i] != -1) return dp[i];
    ans = max(q[i][0] + solve(i + q[i][1] + 1, q, dp), solve(i + 1, q, dp));
    dp[i] = ans;
    return ans;
  }
  long long mostPoints(vector < vector < int >> & q) {
    int n = q.size();
    vector < long long > dp(n, -1);
    return solve(0, q, dp);
  }
};