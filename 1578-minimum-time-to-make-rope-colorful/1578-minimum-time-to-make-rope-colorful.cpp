class Solution {
public:
    
    int minCost(string s, vector<int>& cost) {
        int n = s.size();
        long dp[n][27]; // dp[i][j] denotes min cost to from string upto index i such that last character(alphabet) used is j
        
        //if we dont have characer j in our string we set dp[i][j] = INT_MAX as it is 
        //not possible to have such a string.
        
        //dp[i][0] = cost to form an empty string i.e remove ith character
        for(int i = 0;i<n;i++){
            if(i==0)
                dp[i][0] = cost[i];
            else 
                dp[i][0] = dp[i-1][0] + cost[i];
        }
        for(int i = 1;i<=26;i++)dp[0][i] = INT_MAX;
        dp[0][s[0]-'a'+1] = 0; // as currently the last character 
                               // upto index 0 can only be the first letter of input
        
        for(int i = 1;i<n;i++){
            for(int j=1;j<=26;j++){
                // for each possible ending character j
                
                if(s[i]-'a'+1 == j){
                    // if character at j is same as the character as s[i]
                    //we have 2 cases
                    dp[i][j] = INT_MAX;
                    for(int k = 0;k<=26;k++){
                        //case 1:
                        // we can keep this one and take minimum from previous iteration
                        // except the one where s[i] = j;
                        // as when s[i] == j there will be identical next to each other
                        if(k==j)continue;
                        dp[i][j] = min(dp[i][j],dp[i-1][k]);
                    }
                    //case 2
                    //we remove the character the j and take the one that ends at j from the previous iteration
                    dp[i][j] = min(dp[i][j],cost[i] + dp[i-1][j]);
                }
                else{
                    // If current j is not equal the charater at s[i]
                    //we have to remove s[i] and take min cost from previous iteration.
                     dp[i][j] = INT_MAX;
                     dp[i][j] = min(cost[i] + dp[i-1][j],dp[i][j]);
                }
            }
        }
        long ans = INT_MAX;
        //take the min as ans froma all possible endings
        for(int i = 1;i<=26;i++)ans = min(ans,dp[n-1][i]);
        return ans;
    }
};