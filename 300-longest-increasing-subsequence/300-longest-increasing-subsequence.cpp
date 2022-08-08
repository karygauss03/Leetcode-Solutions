class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        int dp[n];
        for (int i=0;i<n;i++){
            dp[i] = 1;
        }
        int ans = 0;
        for (int i=1;i<n;i++){
            for (int j=0;j<i;j++){
                if (a[i]>a[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        for (int i = 0;i<n;i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};