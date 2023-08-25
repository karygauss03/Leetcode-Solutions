class Solution {
public:
  
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(),n=s2.size();
        bool dp[m+1][n+1];
          memset(dp,0,sizeof(dp));
          //return false if length of s3 is not equals to sum of length of s1 and s2
          if(s3.size()!=m+n)
            return false;
          for(int i=0;i<=m;i++)
          {
            for(int j=0;j<=n;j++)
            {
            if(i==0&&j==0)// if any of the two string s1 and s2 is empty
              dp[i][j]=true;
            //if s1 is empty string
            else if(i==0)
            {
              if(s2[j-1]==s3[j-1])
                dp[i][j]=dp[i][j-1];
            }//if s2 is empty string
            else if(j==0)
            {
              if(s1[i-1]==s3[i-1])
                dp[i][j]=dp[i-1][j];
            }//if the current character of s3 matches with current character of s1 but not s2
            else if(s1[i-1]==s3[i-1+j]&&s2[j-1]!=s3[i-1+j])
              dp[i][j]=dp[i-1][j];
            //if the current character of s3 matches with current character of s2 but not s1
            else if(s2[j-1]==s3[i-1+j]&&s1[i-1]!=s3[i-1+j])
              dp[i][j]=dp[i][j-1];
            //current character of s3 matches with current character of s1 and s2 both
            else if(s1[i-1]==s3[i-1+j]&&s2[j-1]==s3[i-1+j])
              dp[i][j]=dp[i-1][j]||dp[i][j-1];
          }
        }
        return dp[m][n];
    }
};