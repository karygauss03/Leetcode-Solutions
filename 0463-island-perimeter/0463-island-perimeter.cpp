class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, -1, 0, 1};
        int side = 0;
        int cells = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    cells++;
                    for(int index=0; index<4; index++){
                        int newi = i + delrow[index];
                        int newj = j + delcol[index];

                        if(newi >= 0 and newj >= 0 and newi < n and newj < m and grid[newi][newj] == 1){                       
                            side++;                            
                        }
                    }
                }               
            }
        }
        cells = cells * 4;
        cells = cells - (side);
        return cells;
        
    }
};