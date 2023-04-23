class Solution {
public:
    const int mod = 1e9 + 7;
    long dp[100001];
    long solve(int idx, string &s, int k){
        if (idx == s.size())
            return 1;

        if (dp[idx] != -1)
            return dp[idx];

        long sum = 0, ans = 0;
        for (int i = idx; i < s.size(); i++)
        {
            sum = (sum * 10 + (s[i] - '0'));
            if (sum >= 1 and sum <= k)
                ans = (ans + solve(i + 1, s, k));
            else
                break;
        }

        return dp[idx] = ans % mod;
    }

    int numberOfArrays(string s, int k)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, s, k);
    }
};