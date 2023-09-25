class Solution {
public:
    int freq[26];
    char findTheDifference(string s, string t) {
        for (auto &c : s) {
            ++freq[c - 'a'];
        }
        for (auto &c : t) {
            --freq[c - 'a'];
        }
        
        for (int i = 0 ; i < 26 ; ++i) {
            if (freq[i] != 0) {
                return  i + 'a';
            }
        }
        return 'a';
    }
};