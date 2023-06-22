class Solution {
  public: int solve(int i, int bag, vector < int > & P, int fee, vector < vector < int >> & dp) {
    if (i >= P.size()) return 0;
    if (dp[i][bag] != -1) return dp[i][bag];
    if (bag == 1) {
      int t1 = P[i] - fee + solve(i + 1, 0, P, fee, dp);
      int t2 = solve(i + 1, 1, P, fee, dp);
      return dp[i][bag] = max(t1, t2);
    } else {
      int t1 = -P[i] + solve(i + 1, 1, P, fee, dp);
      int t2 = solve(i + 1, 0, P, fee, dp);
      return dp[i][bag] = max(t1, t2);
    }
  }
  int maxProfit(vector < int > & P, int fee) {
    vector < vector < int >> dp(P.size() + 1, vector < int > (2, -1));
    return solve(0, 0, P, fee, dp);
  }
};