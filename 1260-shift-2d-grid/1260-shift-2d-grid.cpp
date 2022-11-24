class Solution {
public:
    int n, m;
    void reverse(vector<vector<int>>& grid, int i, int j){
        while(i < j){
            int row_i = i / m, col_i = i % m;
            int row_j = j / m, col_j = j % m;
            int tmp = grid[row_i][col_i];
            grid[row_i][col_i] = grid[row_j][col_j];
            grid[row_j][col_j] = tmp;
            i++, j--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        n=grid.size(), m = grid[0].size();
        k %= (m * n);
        reverse(grid, 0, n * m - 1);
        reverse(grid, 0, k - 1);
        reverse(grid, k, n * m - 1);
        return grid;
    }
};