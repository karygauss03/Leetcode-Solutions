class Solution {
public:
    int freq[26], secondFreq[26], ans = 0;
    void solve(int i, vector<string>& words, vector<int>& score){
        if (i == words.size()) {
            int sc = 0;
            for (int i = 0 ; i < 26; ++i) {
                if (secondFreq[i] > freq[i]) return;
                sc += score[i] * secondFreq[i];
            }
            ans = max(ans, sc);
            return;
        }
        solve(i + 1, words, score);
        for (auto &c : words[i]) {
            secondFreq[c - 'a']++;
        }
        solve(i + 1, words, score);
        for (auto &c : words[i]) {
            secondFreq[c - 'a']--;
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for (auto &c : letters) {
            freq[c - 'a']++;
        }
        solve(0, words, score);
        return ans;
    }
};