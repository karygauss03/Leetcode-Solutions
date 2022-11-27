class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size();
        if (n < 3) return 0;
        int dp[n + 5];
        memset(dp, 0, sizeof dp); // dp[i] means the number of arithmetic slices ending with a[i]
        if (a[2] - a[1] == a[1] - a[0]) {
            dp[2] = 1;
        } 
        int ans = dp[2];
        for (int i = 3 ; i < n ; i++){
            if (a[i] - a[i - 1] == a[i - 1] - a[i - 2]){
                dp[i] = dp[i - 1] + 1;
            }
            ans += dp[i];
        }
        return ans;
    }
};