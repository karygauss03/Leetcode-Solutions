class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> a(n, 0);
        for (auto& shift : shifts) {
            int l = shift[0], r = shift[1] + 1, op = shift[2];
            if (shift[2] == 0) op = -1;
            a[l] += op;
            if (r < n) a[r] -= op;
        }
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += a[i];
            cur %= 26;
            if (cur < 0) cur += 26;
            s[i] = 'a' + (s[i] -'a' + cur) % 26;
        }
        return s;
    }
};