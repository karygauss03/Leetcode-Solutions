class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        unordered_map<char, int> freq;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            freq[s[i]]++;
            while (freq['a'] >= 1 && freq['b'] >= 1 && freq['c'] >= 1) {
                ans += (n - i);
                freq[s[j]]--;
                ++j;
            }
        }
        return ans;
    }
};