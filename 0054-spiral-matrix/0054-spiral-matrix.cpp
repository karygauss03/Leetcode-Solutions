class Solution {
public:
    int i;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int sr = 0, sc = 0, er = matrix.size() - 1, ec = matrix[0].size() - 1;
        while (sr <= er && sc <= ec) {
            for (i = sc ; i <= ec && sr <= er ; ++i) {
                ans.push_back(matrix[sr][i]);
            }
            ++sr;
            
            for (i = sr ; i <= er && sc <= ec ; ++i) {
                ans.push_back(matrix[i][ec]);
            }
            --ec;
            
            for(i = ec ; i >= sc && sr <= er; --i){
                ans.push_back(matrix[er][i]);
            }
            --er;
            
            for (i = er ; i >= sr && sc <= ec ; --i) {
                ans.push_back(matrix[i][sc]);
            }
            ++sc;
        }
        return ans;
    }
};