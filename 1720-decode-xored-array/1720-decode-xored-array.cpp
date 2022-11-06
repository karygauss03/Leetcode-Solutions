class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> ans;
        ans.push_back(first);
        for (int i = 0 ; i < n ; i++){
            ans.push_back(ans[ans.size() - 1] ^ encoded[i]);
        }
        return ans;
    }
};