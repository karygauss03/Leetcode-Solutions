class Solution {
public:
    int n, m;
    bool vis[55][55];
    void dfs(int r, int c, int src_color, int new_color, vector<vector<int>> &image){
        if (r < 0 || c < 0 || r >= n || c >= m) return;
        if (image[r][c] != src_color) return ;
        if (vis[r][c]) return;
        vis[r][c] = true;
        image[r][c] = new_color;
        dfs(r - 1, c, src_color, new_color, image);
        dfs(r + 1, c, src_color, new_color, image);
        dfs(r, c + 1, src_color, new_color, image);
        dfs(r, c - 1, src_color, new_color, image);
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size(), m = image[0].size();
        memset(vis, 0, sizeof vis);
        
        dfs(sr, sc, image[sr][sc], color, image);
        
        return image;
    }
};