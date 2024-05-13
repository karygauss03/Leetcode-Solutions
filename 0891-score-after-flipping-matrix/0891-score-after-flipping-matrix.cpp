class Solution {
public:
    int matrixScore(vector<vector<int>>& g) {
        int ans=0,n=g.size(),m=g[0].size();
        for(int i=0; i<n; i++) {
            if(g[i][0]==0) {
                for(int j=0; j<m; j++) g[i][j]^=1;
            }
        }
        for(int i=1; i<m; i++) {
            int set=0;
            for(int j=0; j<n; j++) set+=(g[j][i]==1);
            if(2*set<n) for(int j=0; j<n; j++) g[j][i]^=1; 
        }
        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++) ans+=(g[i][j]==1)*(1<<(m-j-1)); 
        return ans;
    }

};