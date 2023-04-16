class Solution {
    long long mod=1e9+7;
public:
    int c(vector<string>&w, string &s,int i,int j,vector<vector<int>>&dp,vector<vector<int>>&pre){
        if(i>=s.size())return 1;
        if(j>=w[0].size())return 0;
        int ans=0;
        if(dp[i][j]!=-1)return dp[i][j];
        int t=0;
        t=pre[j][s[i]-'a'];
        ans = (c(w,s,i,j+1,dp,pre)%mod + ((t%mod)*(c(w,s,i+1,j+1,dp,pre)%mod))%mod)%mod;
        dp[i][j]=ans;
        return ans;
    }
    int numWays(vector<string>& w, string s) {
        int n=s.size(),m=w[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        vector<vector<int>>pre(m,vector<int>(26,0));
        for(int j=0;j<m;j++){
            for(int i=0;i<w.size();i++){
                pre[j][w[i][j]-'a']++;
            }
        }
        return c(w,s,0,0,dp,pre);
    }
};