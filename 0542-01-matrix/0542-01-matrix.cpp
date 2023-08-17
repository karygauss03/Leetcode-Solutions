class cell{
public:
    int row, col;
    cell(int r, int c)
    {
        row=r; col=c;
    }
};
class Solution {
public:
    bool isvalid(int r, int c, int n, int m)
    {
        if(r>=0 && r<n && c>=0 && c<m)
             return true;
        return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,-1));
        
        queue<cell>q;
        
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(mat[row][col]==0)
                {   cell c=cell(row, col);
                    q.push(c);
                    ans[row][col]=0;
                }
                
            }
        }
        int level=0;
        vector<pair<int,int>>dirs{{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty())
        {
            int sz=q.size();
            
            while(sz--)
            {
                cell curCell = q.front();
                q.pop();
                
                for(auto p:dirs)
                {
                    int nextCellRowNo=curCell.row + p.first;
                    int nextCellColNo=curCell.col + p.second;
                    
                    if(isvalid(nextCellRowNo, nextCellColNo, n, m) && ans[nextCellRowNo][nextCellColNo]==-1)
                    {
                        q.push(cell(nextCellRowNo, nextCellColNo));
                        ans[nextCellRowNo][nextCellColNo]=level+1;
                    }
                }
            }
            level++;
        }
        return ans;
    }
};