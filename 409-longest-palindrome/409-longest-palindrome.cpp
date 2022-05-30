class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> ma;
        
        for (char x : s){
            ma[x]++;
        }
        int sum = 0;
        if (ma.size() == 1){
            for (auto it : ma){
                sum += it.second;
            }
            return sum;
        }
        
        for (auto it : ma){
            if (it.second % 2 == 0){
                sum += it.second;
            }
            else {
                sum += it.second - 1;
            }
        }
        if (sum == s.size()) return sum;
        return sum + 1;
    }
};