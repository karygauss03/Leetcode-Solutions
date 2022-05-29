class Solution {
public:
    int freq[125];
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        
        for (int i = 0 ; i < n ; i++){
            freq[ages[i]]++;
        }
        int ans = 0;
        for (int i = 1 ; i <= 120 ; i++){
            for (int j = 1 ; j <= 120 ; j++){
                if (j <= 0.5*i + 7 || j > i || (j > 100 && i < 100)){
                    continue;
                }
                if (i == j){
                    ans += (freq[i] - 1)*freq[i];
                }
                else {
                    ans += freq[i] * freq[j];
                }
            }
        }
        return ans;
    }
};