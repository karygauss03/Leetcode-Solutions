class Solution {
public:
    int m, n;
    
    int solve(vector<vector<vector<int>>> &dp ,vector<vector<bool>> &vis, vector<vector<int>>& grid, int x, int y, int k){
        
        if(x < 0 || y < 0 || x >= m || y >= n || vis[x][y]) return 1e6;
		
        if(x == 0 && y == 0) return dp[x][y][k] = 0;
        
        if(dp[x][y][k] != -1) return dp[x][y][k];
        
        if(grid[x][y]){
            if(k>0) k--;
            else return dp[x][y][k] = 1e6;
        }
        vis[x][y] = 1;
        int left = 1+solve(dp,vis,grid,x,y-1,k);
        int right = 1+solve(dp,vis,grid,x,y+1,k);
        int up = 1+solve(dp,vis,grid,x-1,y,k);
        int down = 1+solve(dp,vis,grid,x+1,y,k);
        vis[x][y] = 0;
        
        return dp[x][y][k] = min({left,right,up,down});
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int ans ;
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        vector<vector<bool>> vis(m, vector<bool>(n,0));
        ans = solve(dp,vis,grid,m-1,n-1,k);
        if(ans >= m*n) return -1;
        return ans;
    }
};