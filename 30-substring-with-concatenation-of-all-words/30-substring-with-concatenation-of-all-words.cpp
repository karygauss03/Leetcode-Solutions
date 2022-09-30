class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        
        int wordLen = words[0].size(), total = words.size(), len = s.size();
        
        unordered_map<string, int> mx;
        for (int i = 0; i < total; i++) mx[words[i]]++;
                
        for (int start = 0; start < wordLen; start++) {
            unordered_map<string, int> m = mx;
            int left = start;
            
            total = words.size();
            
            for (int i = start; i < len; i += wordLen) {
                string t = s.substr(i, wordLen);
                if (--m[t] >= 0) total--;

                while (m[t] < 0) {
                    if (m[s.substr(left, wordLen)]++ >= 0) total++;
                    left += wordLen;
                }

                if (!total) ans.push_back(left);
            }
        }

        return ans;
    }
};