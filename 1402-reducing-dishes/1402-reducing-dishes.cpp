class Solution {
public:
    vector < vector <int> > dp;
    int solve(vector <int>& a, int n, int m) {
        if (n >= a.size()) {
            return 0;
        }
        if (dp[n][m] != -1) {
            return dp[n][m];
        }
        return dp[n][m] = max(solve(a, n + 1, m + 1) + m*a[n], solve(a, n + 1, m));
    }
    int maxSatisfaction(vector<int>& a) {
        sort(a.begin(), a.end());
        dp.assign(a.size() + 1, vector <int> (a.size() + 1, -1) );
        return solve(a, 0, 1);
    }
};