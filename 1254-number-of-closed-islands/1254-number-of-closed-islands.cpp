class Solution {
public:
    bool vis[105][105];
    void dfs(vector<vector<int>>& grid, int i, int j, bool &isClawzed) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j] || grid[i][j]==1) return;
        if((i==0 || i==grid.size()-1 || j==0 || j==grid[0].size()-1) && grid[i][j]==0) isClawzed=false;
        vis[i][j]=1;
        dfs(grid, i-1, j, isClawzed);
        dfs(grid, i+1, j, isClawzed);
        dfs(grid, i, j-1, isClawzed);
        dfs(grid, i, j+1, isClawzed);
        return;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans = 0;
        bool isClawzed=true;
        memset(vis, 0, sizeof vis);
        
        for(int i=1;i<n-1;i++) {
            for(int j=1;j<m-1;j++) {
                if(grid[i][j]==0 && !vis[i][j]) {
                    isClawzed=true;
                    dfs(grid, i, j, isClawzed);
                    if(isClawzed) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};