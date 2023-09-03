class Solution {
public:
    map<string,int>m;
    int c(int i,string &s,vector<int>&dp){
        if(i>=s.size())return 0;
        int ans=INT_MAX;
        if(dp[i]!=-1)return dp[i];
        ans = 1 + c(i+1,s,dp);
        string k="";
        for(int j=i;j<s.size();j++){
            k+= s[j];
            if(m[k]){
                ans=min(ans,c(j+1,s,dp));
            }
        }
        return dp[i]=ans;
    }
    int minExtraChar(string s, vector<string>& d) {
        for(auto i : d)m[i]++;
        vector<int>dp(s.size(),-1);
        return c(0,s,dp);
    }
};