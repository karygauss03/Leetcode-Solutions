class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        vector<vector<int>> distance(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                if(grid[i][j]==1){
                    distance[i][j]=0;
                    q.push({i,j});
                }
        }
        vector<pair<int,int>> moves={{1,0},{0,1},{-1,0},{0,-1}};
        int ans=-1;
        while(q.size()){
            int s=q.size();
            while(s--){
                auto [i,j]=q.front();
                q.pop();
                for(auto &[a,b]:moves){
                    int x=i+a;
                    int y=j+b;
                    if(x<0 or y<0 or x>=n or y>=n or distance[x][y]!=-1)
                        continue;
                    distance[x][y]=distance[i][j]+abs(x-i)+abs(y-j);
                    ans=max(ans,distance[x][y]);
                    q.push({x,y});
                }
            }
        }
        return ans;
    }
};