class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = (m * n)  - 1;
        if(target<matrix[0][0] || target>matrix[n-1][m-1]) return false;
        
        while (l <= r){
            int mid = l +(r - l) / 2;
            if (target == matrix[mid/m][mid%m]) return true;
            if (target > matrix[mid/m][mid%m]) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};