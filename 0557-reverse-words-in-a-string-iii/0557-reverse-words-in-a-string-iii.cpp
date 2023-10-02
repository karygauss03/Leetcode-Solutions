class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string tmp = "";
        for (const char& c: s){
            
            if (c == ' '){
                reverse(tmp.begin(), tmp.end());
                ans += tmp;
                ans += ' ';
                tmp = "";
            }
            else {
                tmp += c;
            }
        }
        reverse(tmp.begin(), tmp.end());
        ans += tmp;
        
        return ans;
    }
};