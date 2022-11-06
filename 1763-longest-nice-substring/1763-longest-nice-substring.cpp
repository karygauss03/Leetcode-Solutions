class Solution {
public:
    string longestNiceSubstring(string s) {
        int max_length = 0, idx = 0;
        for (int i = 0 ; i < s.size() ; i++){
            int lower = 0, upper = 0;
            for (int j = i ; j < s.size() ; j++){
                if (s[j] >= 'a'){
                    lower |= 1<<(s[j] - 'a');
                }
                else {
                    upper |= 1<<(s[j] - 'A');
                }
                if ((upper^lower) == 0){  //s[i] .. s[j] is a nice substring
                    if (max_length < j - i + 1){
                        max_length = j - i + 1;
                        idx = i;
                    }
                }
            }
        }
        if (max_length == 0) return "";
        return s.substr(idx,max_length);
    }
};