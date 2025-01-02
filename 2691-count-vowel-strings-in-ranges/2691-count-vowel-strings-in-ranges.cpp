class Solution {
private:
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    bool isStringStartAndEndWithVowel(string s) {
        return vowels.find(s[0]) != vowels.end() && vowels.find(s[s.size() - 1]) != vowels.end();
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int q = queries.size(), n = words.size();
        vector<int> ans;
        vector<int> prefix(n, 0);
        prefix[0] = isStringStartAndEndWithVowel(words[0]) ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + (isStringStartAndEndWithVowel(words[i]) ? 1 : 0);
        }
        int i = 0;
        while (q--) {
            int l = queries[i][0], r = queries[i][1];
            ++i;
            if (l == 0) {
                ans.push_back(prefix[r]);
            }
            else {
                ans.push_back(prefix[r] - prefix[l - 1]);
            }
        }
        return ans;
    }
};