class Solution {
public:

    double dp[30][30][105];
    int X[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };
    int Y[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };

    double dfs(int i,int j,int k, int n)
    {
        if(i < 0 || j < 0 ||i >= n || j >= n) return 0;
        if(k == 0) return 1;
        if(dp[i][j][k] != 0) return dp[i][j][k];

        double res = 0;

        for(int l = 0;l < 8; ++l)
        {
          int x = i + X[l];
          int y = j + Y[l];
          res += dfs(x,y,k-1,n);
        }
        return dp[i][j][k] += (res/8.0);
    }

    double knightProbability(int n, int k, int row, int column) {

        memset(dp,0,sizeof(dp));
        return dfs(row,column,k,n); 
    }
};