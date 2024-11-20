class Solution {
private:
    bool shouldShrinkWindow(int freq[], int freq2[], int k) {
        return freq[0] - freq2[0] < k || freq[1] - freq2[1] < k || freq[2] - freq2[2] < k;
    }
public:
    int takeCharacters(string s, int k) {
        int freq[3];
        for (auto& c: s) {
            freq[c - 'a']++;
        }
        if (freq[0] < k || freq[1] < k || freq[2] < k) {
            return -1;
        }
        int freq2[3] = {0, 0, 0};
        int l = 0, cur = 0;
        for (int r = 0; r < s.size(); ++r) {
            freq2[s[r] - 'a']++;
            while (shouldShrinkWindow(freq, freq2, k) && l <= r) {
                freq2[s[l++] - 'a']--;
            }
            cur = max(cur, r - l + 1);
        }
        return s.size() - cur;
    }
};