class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string ans = "";
        int freq[26];
        for (auto &c : s) {
            freq[c - 'a']++;
        }
        int i = 25;
        while(i >= 0) {
            if (freq[i] <= 0) {
                --i;
                continue;
            }
            ans += string(min(freq[i], repeatLimit), i + 'a');
            freq[i] -= repeatLimit;
            if (freq[i] > 0) {
                int j = i - 1;
                while (j >= 0 && freq[j] <= 0) {
                    --j;
                }
                if (j < 0) break;
                ans += (j + 'a');
                freq[j]--;
            }
        }
        return ans;
    }
};