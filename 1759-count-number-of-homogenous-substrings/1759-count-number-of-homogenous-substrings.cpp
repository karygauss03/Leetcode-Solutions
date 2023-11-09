class Solution {
public:
    int MOD = 1e9 + 7;
    int countHomogenous(string s) {
        int cnt = 0;
        int ans = 0;
        for (int i = 0 ; i < s.size() ; ++i) {
            if (i == 0 || s[i] == s[i - 1]) {
                ++cnt;
            }
            else {
                cnt = 1;
            }
            ans = (ans + cnt) % MOD;
        }
        return ans;
    }
};