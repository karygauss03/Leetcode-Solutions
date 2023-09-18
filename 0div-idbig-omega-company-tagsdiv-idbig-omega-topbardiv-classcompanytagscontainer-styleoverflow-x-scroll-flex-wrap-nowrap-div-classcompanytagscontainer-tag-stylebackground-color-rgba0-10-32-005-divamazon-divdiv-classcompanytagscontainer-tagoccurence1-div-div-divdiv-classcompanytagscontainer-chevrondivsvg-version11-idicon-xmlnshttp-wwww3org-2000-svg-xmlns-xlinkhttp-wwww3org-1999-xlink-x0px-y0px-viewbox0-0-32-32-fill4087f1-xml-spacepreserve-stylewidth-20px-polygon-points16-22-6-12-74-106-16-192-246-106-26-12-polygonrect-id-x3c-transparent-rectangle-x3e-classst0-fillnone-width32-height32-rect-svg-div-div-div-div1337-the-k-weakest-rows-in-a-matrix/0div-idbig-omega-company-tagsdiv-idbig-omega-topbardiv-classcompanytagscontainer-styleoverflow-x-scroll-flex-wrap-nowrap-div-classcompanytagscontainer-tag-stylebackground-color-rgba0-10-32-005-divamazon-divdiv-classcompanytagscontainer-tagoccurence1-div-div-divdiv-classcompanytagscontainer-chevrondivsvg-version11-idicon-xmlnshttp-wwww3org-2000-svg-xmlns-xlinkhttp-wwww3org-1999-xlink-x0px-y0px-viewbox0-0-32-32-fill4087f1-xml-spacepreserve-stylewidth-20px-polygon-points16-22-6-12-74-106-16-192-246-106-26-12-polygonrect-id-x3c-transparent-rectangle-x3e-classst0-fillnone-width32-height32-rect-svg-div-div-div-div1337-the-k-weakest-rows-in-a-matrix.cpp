class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int,int>> power;
        
        for (int i = 0 ; i < n ; i++){
            int score = 0;
            for (int j = 0 ; j < m ; j++){
                if (mat[i][j] == 1){
                    score++;
                }
            }
            power.push_back({score, i});
        }
        
        sort(power.begin(), power.end());
        vector<int> ans;
        for (int i = 0 ; i < k ; i++){
            ans.push_back(power[i].second);
        }
        return ans;
    }
};