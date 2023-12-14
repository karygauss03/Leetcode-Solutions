class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) noexcept {
        const int rows = size(grid);
        const int cols = size(grid[0]);

        vector<int> rs(rows);
        vector<int> cs(cols);
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c) {
                rs[r] += grid[r][c];
                cs[c] += grid[r][c];
            }
        
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                grid[r][c] = rs[r] + cs[c] - (rows - rs[r]) - (cols - cs[c]);

        return grid;
    }
};