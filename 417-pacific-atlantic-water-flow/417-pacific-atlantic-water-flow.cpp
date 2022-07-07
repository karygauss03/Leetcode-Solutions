class Solution {
public:
    vector<int>dirs={0,1,0,-1,0};
    void bfs(vector<vector<int>>& heights,vector<vector<int>>& vis,queue<pair<int,int>>q)
    {
        while(!q.empty())
        {
            int x=q.front().first,y=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                if(x+dirs[k]>=0 && y+dirs[k+1]>=0 && x+dirs[k]<heights.size() && y+dirs[k+1]<heights[0].size() && vis[x+dirs[k]][y+dirs[k+1]]==0&&heights[x+dirs[k]][y+dirs[k+1]]>=heights[x][y])
                {
                    vis[x+dirs[k]][y+dirs[k+1]]=1;
                    q.push({x+dirs[k],y+dirs[k+1]});
                }
                    
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>>res;
        vector<vector<int>>visp(m,vector<int>(n)),visa(m,vector<int>(n));
        queue<pair<int,int>>qa,qp;
        for(int i=0;i<m;i++)
        {
            visp[i][0]=1;
            visa[i][n-1]=1;
            qp.push({i,0});
            qa.push({i,n-1});
        }
        
        for(int j=0;j<n;j++)
        {
            visp[0][j]=1;
            visa[m-1][j]=1;
            qp.push({0,j});
            qa.push({m-1,j});
        }
        
        bfs(heights,visa,qa);
        bfs(heights,visp,qp);
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(visp[i][j] && visa[i][j])
                    res.push_back({i,j});
        return res;
        
    }
};