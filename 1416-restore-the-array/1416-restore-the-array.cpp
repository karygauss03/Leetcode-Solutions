class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[12], n, id;
    int numberOfArrays(string s, int k) {
        n = s.size();
        dp[n % 12] = 1;
        for (int i = n - 1; i >= 0; --i) {
            long cur = 0, tmp = 0;
            id = i % 12;
            for (int j = i ; j < s.size() ; ++j) {
                cur = (cur * 10) + (s[j] - '0');
                if (cur < 1 || cur > k)
                    break;
                tmp = (tmp + dp[(j + 1) % 12]);
            }
            dp[id] = tmp % mod;
        }
        return dp[0];
    }
};