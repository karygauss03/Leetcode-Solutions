class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans = {pref[0]};
        for (int i = 1 ; i < pref.size() ; i++){
            ans.push_back(pref[i - 1] ^ pref[i]);
        }
        return ans;
    }
};