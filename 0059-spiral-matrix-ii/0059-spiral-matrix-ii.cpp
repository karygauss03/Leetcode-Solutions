class Solution {
public:
    int i;
    int cnt = 1;
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int sr = 0, sc = 0, er = n - 1, ec = n - 1;
        while (sr <= er && sc <= ec) {
            for (i = sc ; i <= ec && sr <= er ; ++i) {
                ans[sr][i] = cnt;
                ++cnt;
            }
            ++sr;
            
            for (i = sr ; i <= er && sc <= ec ; ++i) {
                ans[i][ec] = cnt;
                ++cnt;
            }
            --ec;
            
            for(i = ec ; i >= sc && sr <= er; --i){
                ans[er][i] = cnt;
                ++cnt;
            }
            --er;
            
            for (i = er ; i >= sr && sc <= ec ; --i) {
                ans[i][sc] = cnt;
                ++cnt;
            }
            ++sc;
        }
        return ans;
    }
};