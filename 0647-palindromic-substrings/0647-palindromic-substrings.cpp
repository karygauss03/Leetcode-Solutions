class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int count=0;
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0){
                    dp[i][j]=1;
                    count++;
                }
                else if(g==1 && s[i]==s[j]){
                    dp[i][j]=1;
                    count++;
                }
                else if(s[i]==s[j] && dp[i+1][j-1]==1){
                    dp[i][j]=1;
                    count++;
                }
            }
        }
        return count;      
    }
};