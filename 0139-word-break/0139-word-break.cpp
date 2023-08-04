class Solution {
public:
    
    bool dp[305];
    int n, m;
    unordered_set<string> words;
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        m = wordDict.size();
        for (auto &word : wordDict){
            words.insert(word);
        }
        
        memset(dp, false, sizeof dp);
        dp[0] = true;
        for (int i =1 ; i <= n ; i++){
            for (int j = i - 1 ; j >= 0 ; j--){
                if (!dp[j]) continue;
                string subS = s.substr(j, i - j);
                if (words.find(subS) != words.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
        
        
    }
};