class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;
        vector<int> freq(26, 0);
        for (auto &c : s) {
            freq[c - 'a']++;
        }
        int cnt = 0;
        for (int i = 0; i < 26; ++i) {
            cnt += (freq[i] & 1);
        }
        return cnt <= k;
    }
};