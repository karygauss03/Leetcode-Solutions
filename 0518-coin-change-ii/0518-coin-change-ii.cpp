class Solution {
public:
     int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int i=0; i<n; i++)
            dp[i][0]=1;
        
        for(int i=0; i<n; i++)
            for(int j=1; j<=amount; j++)
                dp[i][j]= ((j-coins[i]>=0)?dp[i][j-coins[i]]:0) + ((i>0)?dp[i-1][j]:0);
            
        return dp[n-1][amount];
    }
};