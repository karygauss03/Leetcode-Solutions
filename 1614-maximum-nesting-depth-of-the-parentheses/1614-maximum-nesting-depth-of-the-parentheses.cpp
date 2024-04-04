class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int open = 0, closed = 0;
        for (auto &c : s) {
            if (c == '(') {
                ++open;
            }
            if (c == ')') {
                ++closed;
            }
            ans = max(ans, open - closed);
        }
        return ans;
    }
};