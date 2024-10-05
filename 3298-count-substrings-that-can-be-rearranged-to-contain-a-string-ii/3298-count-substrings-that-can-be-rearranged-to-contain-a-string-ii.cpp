class Solution {
private:
    bool isValid(vector<int> &v1, vector<int> &v2) {
        for (int i = 0; i < 26; ++i) {
            if (v2[i] != 0 && v1[i] < v2[i]) {
                return false;
            }
        }
        return true;
    }
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> word2Freq(26, 0);
        vector<int> subFreq(26, 0);

        int n = word1.size(), m = word2.size();
        for (auto &w : word2) {
            word2Freq[w - 'a']++;
        }

        int l = 0;
        long long ans = 0;
        char cur;
        int r;
        for (r = 0; r < n; ++r) {
            cur = word1[r];
            subFreq[cur- 'a']++;
            while (isValid(subFreq, word2Freq)) {
                ans += (n - r);
                cur = word1[l++];
                subFreq[cur - 'a']--;
            }
        }

        return ans;
    }
};