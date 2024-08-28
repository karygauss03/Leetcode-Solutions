class Solution {
public:
    void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j, int& ans){
        int n = grid1.size(), m = grid1[0].size();
        if(i<0 or i>=n or j<0 or j>=m or grid2[i][j]==0) return;
        if(grid1[i][j]==0 and grid2[i][j]==1){
            ans = false; 
            return;
        }
        grid2[i][j] = 0;
        int x[] = {0,0,-1,1}, y[] = {1,-1,0,0};
        for(int at=0;at<4;at++){
            dfs(grid1,grid2,i+x[at],j+y[at],ans);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size(), res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ans = 1;
                if(grid2[i][j]==1){
                    dfs(grid1,grid2,i,j,ans);
                    res += ans;
                }
            }
        }
        return res;
    }
};