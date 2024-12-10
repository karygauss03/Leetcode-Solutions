class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<vector<int>> freq(26, vector<int>(3, -1));
        int cur = 0, ans = -1;
        char prev = s[0];
        for (auto &c : s) {
            if (c == prev) {
                ++cur;
            }
            else {
                cur = 1;
                prev = c;
            }

            auto it = min_element(freq[c - 'a'].begin(), freq[c - 'a'].end());
            if (cur > *it) {
                // cout << "before: " << *it << endl;
                *it = cur;
                // cout << "after: " << *it << endl;
            }
        }

        for (int i = 0; i < 26; ++i) {
            ans = max(ans, *min_element(freq[i].begin(), freq[i].end()));
        }

        return ans;
    }
};