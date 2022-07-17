/*
the key to solving this question are these fundamental observations
lets call state as (n,k)
thinking in a dp/memoization manner, is there any dependancy among the states?
lets say I want to find (n,k) 
state(n,k) = state(n-1,k) + state(n-1,k-1)... and so on, these are min(n,k)terms.
How did I get at this?
Well this is the key insight,
lets say I want to find for (n=4,k=2)
now how to do this?
1) for all the n-1 = 3 with k=2 I can just add the 4 th no in the end
like this 
     312_(add 4 at the end, it wont contribute to any new inversions)
     and other such
2) for all n-1 with k=1 I can add the 4th number at position 3 causing 1 inversion for a total 2 inversions
 eg- 2 1 _ 3 (add 4 at the 3rd place for all the 3 digit arrays having 1 inversion to create a 4 digit array of 2 inversions as the 4 at 3rd place will always contribute 1 extra inversion)
 
and so on.... we add them to get the ans
(can easily prove that these terms are correct and indeed encompass all the set of possibilities)
make a table and use pen and paper to really understand

this is the solution basically

*/

class Solution {
public:
    int mod = 1000000007;
    int dp[1007][1007];
    int kInversePairs(int n, int k) {
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
               if(i==0)dp[i][j]=0;
               if(j==0)dp[i][j]=1;
               if(i==0) continue; //( no point in making cumulative arr for this )
               //now lets find value for n>=1
                // for each j basically I want sum of min(n,k+1) terms of previous row
                //for faster computation i use cumulative array
                int val= min(i,j+1);
                if(val==(j+1)) dp[i][j]=dp[i-1][j];
                else dp[i][j]= (dp[i-1][j] - dp[i-1][j-val] + mod)%mod;
                
            }
            if(i==n)continue; // dont want to make cumulative array out of the last row
            for(int j=1;j<=k;j++) dp[i][j]= (dp[i][j]+dp[i][j-1])%mod;
            
        }
        return dp[n][k];
    }
};