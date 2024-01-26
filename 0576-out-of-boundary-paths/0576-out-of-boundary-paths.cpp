class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        auto dp=vector<vector<int>>(m,vector<int>(n,0));
        auto temp=dp;
        int M=1e9+7;
        for(int k=0;k<N;k++){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    long a=(i-1<0) ? 1: dp[i-1][j];
                    long b=(i+1>=m) ? 1: dp[i+1][j];
                    long c=(j-1<0) ? 1: dp[i][j-1];
                    long d=(j+1>=n) ? 1: dp[i][j+1];
                    
                    temp[i][j]=(a+b+c+d)%M;
                }
            }
            dp=temp;
        }
        return dp[i][j];
    }
};