class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        for (int i = 1 ; i < n ; i++){
            for (int j = 1 ; j < m ; j++){
                if (matrix[i - 1][j - 1] != matrix[i][j]) return false;
            }
        }
        return true;
    }
};