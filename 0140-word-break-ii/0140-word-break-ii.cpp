class Solution {
public:
    vector<string> ans;
    unordered_set<string> dict;
    
    void solve(string& s, int start, string cur = "") {
        if (start == s.size()) {
            cur.pop_back();
            ans.push_back(cur);
            return;
        }
        
        for (int end = start; end < s.size(); ++end) {
            string word = s.substr(start, end - start + 1);
            if (dict.find(word) != dict.end()) {
                solve(s, end + 1, cur + word + " ");
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto &word : wordDict) {
            dict.insert(word);
        }
        solve(s, 0);
        return ans;
    }
};