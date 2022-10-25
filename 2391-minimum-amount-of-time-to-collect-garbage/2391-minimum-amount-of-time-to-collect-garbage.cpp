class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int last_p = 0, last_m = 0, last_g = 0;
        int g = 0, p = 0, m = 0;
        //prefix sum of travel time
        int pref[travel.size() + 1];
        pref[0] = 0;
        for (int i = 1 ; i < travel.size() + 1 ; i++){
            pref[i] = pref[i - 1] + travel[i - 1];
        }
        int ans = 0;
        for (int i = 0 ; i < garbage.size() ; i++){
            for (int j = 0 ; j < garbage[i].size() ; j++){
                if (garbage[i][j] == 'P'){
                    p++;
                }
                if (garbage[i][j] == 'G'){
                    g++;
                }
                if (garbage[i][j] == 'M'){
                    m++;
                }
            }
            if (p != 0){
                ans += p + pref[i] - pref[last_p];
                last_p = i;
            }
            if (g != 0){
                ans += g + pref[i] - pref[last_g];
                last_g = i;
            }
            if (m != 0){
                ans += m + pref[i] - pref[last_m];
                last_m = i;
            }
            p = 0, g = 0, m = 0;
        }
        return ans;
    }
};