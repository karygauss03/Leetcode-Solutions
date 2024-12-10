class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<vector<int>> freq(26, vector<int>(n + 1, 0));
        int cur = 1, ans = -1;
        char prev = s[0];
        freq[prev - 'a'][cur] = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == prev) {
                ++cur;
                freq[s[i] - 'a'][cur] += 1;
            }
            else {
                cur = 1;
                prev = s[i];
                freq[s[i] - 'a'][1] += 1;
            }
        }

        for (int j = 0 ; j < 26; ++j) {
            for (int i = n - 1; i >= 1; --i) {
                freq[j][i] += freq[j][i + 1];
                if (freq[j][i] >= 3) {
                    ans = max(ans, i);
                    break;
                }
            }
        }

        return ans;
    }
};