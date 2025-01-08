class Solution {
private:
    bool isPrefixAndSuffix(string s, string t) {
        if (s.size() > t.size()) return false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) return false;
        }
        for (int i = s.size() - 1, j = t.size() - 1; i >= 0; --i, --j) {
            if (s[i] != t[j]) return false;
        }
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0, n = words.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans += isPrefixAndSuffix(words[i], words[j]) ? 1 : 0;
            }
        }
        return ans;
    }
};