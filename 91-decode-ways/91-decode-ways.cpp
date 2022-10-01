class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (s[0] == '0') return 0;
        
        if (n == 1) return 1;
        
        int dp[n];
        memset(dp, 0, sizeof dp);
        dp[n - 1] = s[n - 1] == '0' ? 0 : 1;
        for (int i = n - 2 ; i >= 0 ; i--){
            if (s[i] == '0'){
                if(s[i-1]-'0'>2 || s[i-1]=='0') return 0;
            }
            else if(s[i+1]=='0'){
                if(s[i]-'0'>2)
                    return 0;
                if(i+2<n)
                    dp[i]=dp[i+2];
                else
                    dp[i]=1;
            }
            else if(stoi(s.substr(i,2))<27&&s[i+2]!='0'){
                if(i+2<n)
                    dp[i]=dp[i+1]+dp[i+2];
                else
                    dp[i]=dp[i+1]+1;
            }
            else {
                dp[i]=dp[i+1];
            }
            
        }
        return dp[0];
    }
};