class Solution {
public:
     int f(int ind1,int ind2,string &x, string &y,vector<vector<int>>&dp ){
       if(ind1<0 || ind2<0)return 0;
        
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        
        if(x[ind1]==y[ind2]){
            
        return dp[ind1][ind2]= 1+f(ind1-1, ind2-1, x, y,dp);
              
        }
        
         return dp[ind1][ind2] =max(f(ind1, ind2-1,x, y,dp), f(ind1-1, ind2, x, y,dp)); 
    }
    int longestPalindromeSubseq(string s) {
        string rev=s;
        reverse(rev.begin(), rev.end());
        int n=s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        return f(n-1, n-1,s, rev,dp);
    }
};