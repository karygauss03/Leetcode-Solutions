class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n  = a.size();
        map<long long, long long> dp[n+1];
        long long ans = 0;

        for( int i = 0; i < n; i++)
        {
            for( int j = 0; j < i; j++)
            {
                long long d = 1LL*a[i] - 1LL*a[j];

                if(dp[j].count( d ) ) 
                {
                    ans += dp[j][d];
                    dp[i][d] += dp[j][d];
                }

                dp[i][d] += 1;
            }
        }
        return ans;
    }
};