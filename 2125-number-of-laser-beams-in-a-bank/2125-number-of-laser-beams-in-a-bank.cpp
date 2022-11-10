class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        int ans = 0;
        int contains[n];
        memset(contains, 0, sizeof contains);
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (bank[i][j] == '1'){        
                    contains[i]++;
                }
            }
        }
        int prev = -1;
        for (int i = 0 ; i < n ; i++){
            if (contains[i] != 0){
                if (prev == -1){
                    prev = contains[i];
                }
                else {
                    ans += prev * contains[i];
                    prev = contains[i];
                }
            }
        }
        return ans;
    }
};