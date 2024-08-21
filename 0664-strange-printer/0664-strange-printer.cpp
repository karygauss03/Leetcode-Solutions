class Solution {

public:

    int strangePrinter(string s) {

        s.erase(unique(s.begin(), s.end()), s.end());   

        int n = s.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));

        for(int i=0; i<n; i++){ 

            dp[i][i] = 1;

            dp[i][i+1] = s[i] == s[i+1] ? 1 : 2;

        }

        

        for(int gap = 2; gap<n; gap++){

            for(int i=0; i+gap<n; i++){

                int j = i + gap;

                dp[i][j] = dp[i+1][j] + 1;

                for(int k=i+1; k<=j; k++){

                    if(s[k] == s[i]){

                        dp[i][j] = min(dp[i][j], dp[i][k-1]+ (j>k? dp[k+1][j] : 0));

                    }

                }

            }

        }

        return dp[0][n-1];

    }

};