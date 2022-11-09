class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        map<string, bool> ma;
        string tmp = "";
        for (auto &c : s){
            tmp += c;
            ma[tmp] = true;
        }
        int ans = 0;
        for (auto &word : words){
            if (ma.find(word) != ma.end()){
                ans++;
            }
        }
        return ans;
    }
};