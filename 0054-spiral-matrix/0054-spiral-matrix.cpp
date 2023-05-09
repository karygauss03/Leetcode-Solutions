class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        int sr = 0, sc = 0, er = n - 1, ec = m - 1;
        while (sr <= er && sc <= ec) {
            for (int i = sc ; i <= ec && sr <= er ; ++i) {
                ans.push_back(matrix[sr][i]);
            }
            ++sr;
            
            for (int i = sr ; i <= er && sc <= ec ; ++i) {
                ans.push_back(matrix[i][ec]);
            }
            --ec;
            
            for(int i = ec ; i >= sc && sr <= er; --i){
                ans.push_back(matrix[er][i]);
            }
            --er;
            
            for (int i = er ; i >= sr && sc <= ec ; --i) {
                ans.push_back(matrix[i][sc]);
            }
            ++sc;
        }
        return ans;
    }
};