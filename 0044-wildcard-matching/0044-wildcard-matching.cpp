class Solution {
public:
    int solve(int i,int j,int &a,int &b,string &s,string &p,vector<vector<int>> &dp){
        if(i==a && j==b)return 1;
        else if(i==a){
            while(j<b && p[j]=='*')j++;
            return j==b;
        }
        else if(i != a && j == b)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        bool c = false;
        while(j<b && p[j]=='*'){j++;c = true;}
        
        if(c)j--;
        if(p[j]=='?'){
            dp[i][j] = solve(i+1,j+1,a,b,s,p,dp);
        }else if(p[j]=='*'){
            dp[i][j] = solve(i+1,j,a,b,s,p,dp)||solve(i,j+1,a,b,s,p,dp);
        }else{
            if(s[i]==p[j]){
                dp[i][j] = solve(i+1,j+1,a,b,s,p,dp);
            }else{
                dp[i][j] = 0;
            }
        }
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        int a = s.length(),b= p.length();
        vector<vector<int>> dp(a,vector<int>(b,-1));
        return solve(0,0,a,b,s,p,dp);
    }
};