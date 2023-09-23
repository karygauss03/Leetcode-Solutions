class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), [](const string& first, const string& second){
        return first.size() < second.size();
    });
        
        for (auto &word: words) {
            for (int i = 0; i < word.size(); ++i) {
                string subString = word.substr(0, i) + word.substr(i + 1);
                dp[word] = max(dp[word], dp.find(subString) == dp.end() ? 1 : dp[subString] + 1);
            }
            ans = max(ans, dp[word]);
        }
        
        return ans;
    }
};