class Solution {
public:
    int minAddToMakeValid(string s) {
        if (s == "") {
            return 0;
        }
        int ans = 0;
        int unbalanced = 0;
        for (auto& c : s) {
            if (c == '(') {
                ++unbalanced;
            }
            else {
                if (unbalanced > 0) {
                    --unbalanced;
                }
                else {
                    ++ans;
                }
            }
        }
        
        return ans + unbalanced;
    }
};