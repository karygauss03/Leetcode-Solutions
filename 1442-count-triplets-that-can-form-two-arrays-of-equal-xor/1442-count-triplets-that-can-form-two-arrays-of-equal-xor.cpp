class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        int pref[arr.size()];
        pref[0] = arr[0];
        for (int i = 1 ; i < arr.size() ; i++){
            pref[i] = pref[i - 1] ^ arr[i];
        }
        
        for (int i = 0 ; i < arr.size() ; i++){
            for (int j = i + 1 ; j < arr.size() ; j++){
                int sub_xor;
                if (i == 0){
                    sub_xor = pref[j];
                }
                else {
                    sub_xor = pref[j] ^ pref[i - 1];
                }
                if (sub_xor == 0){
                    ans += (j - i);
                }
            }
        }
        return ans;
    }
};