class Solution {
public:
    vector<vector<int>> next = {{0,1},{0,-1},{1,0},{-1,0}};
    int getMaximumGold(vector<vector<int>>& g) {
        int res =0,n=g.size(),m=g[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                res = max(res, backTrack(g,i,j,n,m));
            }
        }
        return res;
    }

    int backTrack(vector<vector<int>>& g, int r, int c, int n, int m) {
        if(!isValid(r, c, n, m) || g[r][c]==0) return 0;
        int currVal = g[r][c];
        g[r][c]=0;
        int res = currVal;
        int nextRes = 0;
        for(int i=0;i<4;i++) {
            int nextR = r + next[i][0];
            int nextC = c + next[i][1];
            nextRes = max(backTrack(g,nextR, nextC,n,m), nextRes);
        }
        g[r][c]=currVal;
        return res + nextRes;
    }

    bool isValid(int r, int c, int n, int m) {
        bool res = (r>=0 && c>=0 && r<n && c<m);
        return res;
    }
};