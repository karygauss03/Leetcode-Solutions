class Solution {
public:
    
    bool do_binary_search(vector<vector<int>>& matrix, int pos, bool is_vertical, int target){
        int l = pos;
        int h = (is_vertical) ? matrix.size() - 1 : matrix[0].size() - 1;
        while (l <= h){
            int mid = (l + h)/2;
            if (is_vertical){
                if (matrix[mid][pos] > target){
                    h = mid - 1;
                }
                else if (matrix[mid][pos] < target){
                    l = mid + 1;
                }
                else return true;
            }
            else {
                if (matrix[pos][mid] > target){
                    h = mid - 1;
                }
                else if (matrix[pos][mid] < target){
                    l = mid + 1;
                }
                else return true;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mn = min(n, m);
        for (int i = 0 ; i < mn ; i++){
            bool vertical = do_binary_search(matrix, i, true, target);
            bool horizontal = do_binary_search(matrix, i, false, target);
            if (vertical || horizontal) return true;
        }
        return false;
    }
};