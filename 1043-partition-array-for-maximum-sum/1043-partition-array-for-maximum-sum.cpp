class Solution {
private:
    int n;
    int dp[505]; //dp[i] = largest sum after partitionning a[0] .. a[i - 1]
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        int mx = arr[0];
        dp[0] = arr[0];
        for (int i = 1 ; i < k ; i++){
            mx = max(mx, arr[i]);
            dp[i] = mx * (i + 1);
        }
        for (int i = k ; i < n ; i++){
            int mx = arr[i];
            for (int j = 1 ; j <= k ; j++){
                mx = max(mx, arr[i - j + 1]);
                dp[i] = max(dp[i], dp[i - j] + mx * j);
            }
        }
        return dp[n - 1];
    }
};