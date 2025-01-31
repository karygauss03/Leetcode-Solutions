class Solution {
public:
    vector<vector<int>> g;
    unordered_map<int,int> check;
    int size;
    int couple[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(int r,int c,vector<vector<int>>& grid,int &count,int &n){
        if(g[r][c]==count) return;
        g[r][c]=count;
        size++;
        for(auto &i:couple){
            int rr = r+i[0];
            int cc = c+i[1];
            if(rr>=0 && cc>=0 && rr<n && cc<n && grid[rr][cc]==1){
                dfs(rr,cc,grid,count,n);
            }
        }
        
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int count=0;
        int ans=0;
        g.resize(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && g[i][j]==0){
                    count++;
                    size=0;
                    dfs(i,j,grid,count,n);
                    check[count]=size;
                    ans = max(ans,size);
                }
            }
        }
        
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==0){
                    count=1;
                    set<int> c;
                    for(auto &ii:couple){
                       int rr = i+ii[0];
                       int cc = j+ii[1];
                       if(rr>=0 && cc>=0 && rr<n && cc<n && g[rr][cc]!=0 && c.count(g[rr][cc])==0){
                           c.insert(g[rr][cc]);
                            count+=check[g[rr][cc]];       
                       }
                    }
                    ans=max(ans,count);
                    
                }
            }
        }
        return ans;   
    }
};