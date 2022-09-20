class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int dp[n+1][m+1];
        for (int i=0;i<=nums1.size();i++){
            for (int j=0;j<=nums2.size();j++){
                dp[i][j] = 0;
            }
        }
        int ans = 0;
        for (int i=nums1.size()-1;i>=0;i--){
            for (int j=nums2.size()-1;j>=0;j--){
                if (nums1[i] == nums2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                ans = max(ans,dp[i][j]);
            }    
        }
        return ans;
    }
};