class Solution {
public:
    bool outFrequencyCheck(unordered_map<char, int> &freq, unsigned long int n) {
        return freq['Q'] <= n/4 && freq['W'] <= n/4 && freq['E'] <= n/4 && freq['R'] <= n/4;
    }
    int balancedString(string s) {
        unordered_map<char, int> freq;
        int ans = s.size(), start = 0;
        for (auto& c : s) {
            freq[c]++;
        }
        for (int i = 0 ; i < s.size() ; ++i) {
            freq[s[i]]--;
            while (start < s.size() && outFrequencyCheck(freq, s.size())) {
                ans = min(ans, i - start + 1);
                freq[s[start++]]++;
            }
        }
        return ans;
    }
};