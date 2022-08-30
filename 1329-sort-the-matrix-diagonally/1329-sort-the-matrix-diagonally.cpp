class Solution {
public:
    void solve(int i, int j, vector<vector<int>> &grid){
        int r=i,c=j;
        int n = grid.size(), m = grid[0].size();
        vector<int> v;
        while(i<n and j<m){
            v.push_back(grid[i][j]);
            i++;
            j++;
        }
        sort(v.begin(),v.end());
        i = r, j = c;
        int index = 0;
        while(i<n and j<m){
            grid[i][j] = v[index];
            i++;
            j++;
            index++;
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int row=0, col = m-1;
        
        for(int j = m-1;j>=0;j--){
            solve(0,j,grid);
        }
        for(int i = 1;i<n;i++){
            solve(i,0,grid);
        }
        return grid;
        
    }
};