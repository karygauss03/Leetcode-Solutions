class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        pair<int, int> coordinates[n * m + 1];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                coordinates[mat[i][j]] = {i, j};
            }
        }

        vector<int> r(n, 0), c(m, 0);
        for (int i = 0; i < arr.size(); ++i) {
            r[coordinates[arr[i]].first]++;
            c[coordinates[arr[i]].second]++;
            if (r[coordinates[arr[i]].first] == m || c[coordinates[arr[i]].second] == n) {
                return i;
            }
        }

        return 0;
    }
};