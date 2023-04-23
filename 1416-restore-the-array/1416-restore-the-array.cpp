class Solution {
public:
    const int mod = 1e9 + 7;
    long dp[100001];
    int n;
    int numberOfArrays(string s, int k) {
        n = s.size();
        dp[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            long cur = 0, tmp = 0;
            for (int j = i ; j < s.size() ; ++j) {
                cur = (cur * 10) + (s[j] - '0');
                if (cur < 1 || cur > k)
                    break;
                tmp = (tmp + dp[j + 1]);
            }
            dp[i] = tmp % mod;
        }
        return dp[0];
    }
};