class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = 0;
        int open = 0, closed = 0;
        for (auto &c : s) {
            if (c == '(') {
                ++open;
                st.push(c);
            }
            else if (c == ')') {
                if (st.top() == '(') {
                    ans = max(ans, open - closed);
                }
                else {
                    st.pop();   
                }
                ++closed;
            }
            else {
                st.push(c);
                ans = max(ans, open - closed);
            }
        }
        return ans;
    }
};