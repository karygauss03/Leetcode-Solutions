class Solution {
private:
    bool isValid(vector<int>& v1, vector<int>& v2) {
        for (int i = 0; i < 26; ++i) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> freq(26, 0);
        vector<int> freq2(26, 0);
        for (auto &c: s1) {
            freq[c - 'a']++;
        }
        
        int l = 0, r = s1.size() - 1;
        for (int i = l; i <= r; ++i) {
            freq2[s2[i] - 'a']++;
        }
        if (isValid(freq, freq2)) {
            return true;
        }
        ++l, ++r;
        while (r < s2.size()) {
            freq2[s2[l - 1] - 'a']--;
            freq2[s2[r] - 'a']++;
            if (isValid(freq, freq2)) {
                return true;
            }
            ++l, ++r;
        }
        
        return false;
    }
};