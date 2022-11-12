class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> ma(26);
        for (int i = 0 ; i < n ; i++){
            ma[s[i] - 'a'].push_back(i);
        }
        int ans = 0;
        for (int i = 0 ; i < 26 ; i++){
            if (ma[i].size() > 0){
                for (int j = 0 ; j < 26 ; j++){
                    int idx = upper_bound(ma[j].begin(), ma[j].end(), ma[i][0]) - ma[j].begin();
                    if (idx != ma[j].size() && ma[j][idx] < ma[i].back()){
                        ans++;
                    }
                }
            }
        }
        return ans;
        
    }
};