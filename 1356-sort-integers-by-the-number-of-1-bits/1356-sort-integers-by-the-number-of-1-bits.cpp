class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> tmp;
        for (auto &a : arr){
            tmp.push_back(make_pair(__builtin_popcount(a), a));
        }
        sort(tmp.begin(), tmp.end());
        vector<int> ans;
        for (auto &t : tmp){
            ans.push_back(t.second);
        }
        return ans;
    }
};