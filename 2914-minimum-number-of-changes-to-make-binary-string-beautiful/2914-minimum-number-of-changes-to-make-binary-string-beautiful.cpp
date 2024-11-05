class Solution {
public:
    int minChanges(string s) {
        if (s.size() == 2) {
            return s[0] != s[1];
        }
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i += 2) {
            if (s[i] != s[i + 1]) {
                ++ans;
            }
        }
        return ans;
    }
};