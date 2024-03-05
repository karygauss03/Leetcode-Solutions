class Solution {
public:
    int minimumLength(string s) {
        if (s.size() == 1) {
            return s.size();
        }
        int l = 0, r = s.size() - 1;
        if (s[l] != s[r]) {
            return s.size();
        }
        char current = s[l];
        while (l < r && s[l] == s[r]) {
            current = s[l];
            while (l <= r && s[l] == current) {
                ++l;
            }
            while (l < r && s[r] == current) {
                --r;
            }
        }
        return r - l + 1;
    }
};