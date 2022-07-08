class Solution {
public:
    
    bool isValid (int i, int j, int n, vector<vector<int>>& grid)
    {
        if (i<0 || j<0 || i>=n || j>=n || grid[i][j]!=0)
            return false;
        
        // mark the cell as visited
        grid[i][j]=2;
        return true;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        
        // when it's impossible to go in top-left or bottom-right cell
        if (grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        
        // Make a queue of vectors to store 3 integers : row, column, moves
        queue<vector<int>>q;
        
        // Start BFS traversal from grid[0][0]  and moves = 0
        q.push({0,0,0});
        
        
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int i=it[0];
            int j=it[1];
            int moves=it[2];
            
            // if we reach bottom-right, return moves+1 as the number of cells travelled will be one more than moves
            if (i==n-1 && j==n-1)
                return moves+1;
            
            // push all valid adjacent cells of the top element of queue, in queue
            if (isValid(i+1,j,n,grid))
                q.push({i+1,j,moves+1});
            
            if (isValid(i-1,j,n,grid))
                q.push({i-1,j,moves+1});
            
            if (isValid(i,j+1,n,grid))
                q.push({i,j+1,moves+1});
            
            if (isValid(i+1,j+1,n,grid))
                q.push({i+1,j+1,moves+1});
            
            if (isValid(i+1,j-1,n,grid))
                q.push({i+1,j-1,moves+1});
            
            if (isValid(i-1,j+1,n,grid))
                q.push({i-1,j+1,moves+1});
            
            if (isValid(i,j-1,n,grid))
                q.push({i,j-1,moves+1});
            
            if (isValid(i-1,j-1,n,grid))
                q.push({i-1,j-1,moves+1});
        }
        
        // queue became empty but still we did not reach bottom-right cell so return -1;
        return -1;
    }
};