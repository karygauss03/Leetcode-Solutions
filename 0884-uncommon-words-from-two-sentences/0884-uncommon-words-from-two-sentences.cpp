class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string both = s1 + " " + s2;
        vector<string> ans;
        unordered_map<string, int> wCnt;
        string word = "";
        for(char c : both) {
            if (c != ' ') {
                word += c;
            } else if (!word.empty()) {
                wCnt[word]++;
                word = "";
            }
        }
        if (!word.empty()) {
            wCnt[word]++;
        }
        for (auto& entry : wCnt) {
            if (entry.second == 1) {
                ans.push_back(entry.first);
            }
        }
        return ans;
    }
};