class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        vector<vector<string>> res;
        if(strs.empty()) return res;
        for(int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            umap[temp].push_back(strs[i]);
        }
        
        for(auto i = umap.begin(); i != umap.end(); i++) {
            res.push_back(i->second);
        }
        return res;
    }
};