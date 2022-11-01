class Solution {
public:
    bool valid(int i, int j, int n, int m){
        return (i < n && i >= 0 && j < m && j >= 0);
    }
    
    int dfs(int r, int c, vector<vector<int>>& grid){
        if (r == grid.size()) return c;
        if (valid (r, c, grid.size(), grid[0].size())){
            if (grid[r][c] == 1){
                if (valid(r, c + 1, grid.size(), grid[0].size()) && grid[r][c + 1] == 1){
                    return dfs(r + 1, c + 1, grid);
                }
            }
            else {
                if(valid(r ,c - 1, grid.size(), grid[0].size()) && grid[r][c - 1] == -1){
                    return dfs(r + 1,c - 1,grid);
                }
            }
        }
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans;
        int cur;
        for (int i = 0 ; i < n ; i++){
            cur = dfs(0, i, grid);
            ans.push_back(cur);
        }   
        return ans;
    }
};