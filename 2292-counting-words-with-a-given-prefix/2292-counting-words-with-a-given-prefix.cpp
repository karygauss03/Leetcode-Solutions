class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (auto& word : words) {
            if (pref.size() > word.size()) {
                continue;
            }
            int i = 0, isPrefix = 1;
            for (int j = 0; j < word.size() && i < pref.size(); ++j, ++i) {
                if (pref[i] != word[j]) {
                    isPrefix = 0;
                    break;
                }
            }
            ans += isPrefix;
        }
        return ans;
    }
};