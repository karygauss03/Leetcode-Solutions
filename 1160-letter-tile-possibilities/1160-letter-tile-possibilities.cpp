class Solution {
public:
    string path = "";
    set<string> ans;
    bool vis[8];
    void solve(string& tiles) {
        if (path.size() > tiles.size()){
            return;
        }
        ans.insert(path);
        for (int i = 0 ; i < tiles.size(); ++i) {
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            path += tiles[i];
            solve(tiles);
            path.pop_back();
            vis[i] = false;
        }
    }
    
    int numTilePossibilities(string tiles) {
        memset(vis, 0, sizeof vis);
        solve(tiles);
        return ans.size() - 1;
    }
};