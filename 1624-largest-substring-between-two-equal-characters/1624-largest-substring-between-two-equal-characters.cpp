class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int firstIndexes[26];
        int ans = -1;
        memset(firstIndexes, -1, sizeof firstIndexes);
        for (int i = 0; i < s.size(); ++i) {
            if (firstIndexes[s[i] - 'a'] != -1) {
                ans = max(ans, i - firstIndexes[s[i] - 'a'] - 1);
                continue;
            }
            firstIndexes[s[i] - 'a'] = i;
            continue;
        }
        return ans;
    }
};