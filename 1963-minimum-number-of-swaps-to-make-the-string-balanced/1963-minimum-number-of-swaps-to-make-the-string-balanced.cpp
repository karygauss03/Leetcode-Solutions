class Solution {
public:
    int minSwaps(string s) {
        int tracked = 0;
        if (s == "") {
            return 0;
        }
        
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '[') {
                ++tracked;
            }
            else {
                if (tracked > 0) {
                    --tracked;
                } 
            }
        }
        return (tracked + 1) / 2;
    }
};