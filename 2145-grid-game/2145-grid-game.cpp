class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long ans = LONG_LONG_MAX;
        long long fir = 0LL, sec = 0LL;
        for (auto &cell : grid[0]) {
            fir += cell;
        }
        for (int i = 0; i < grid[0].size(); ++i) {
            fir -= grid[0][i];
            ans = min(ans, max(fir, sec));
            sec += grid[1][i];
        }
        return ans;
    }
};