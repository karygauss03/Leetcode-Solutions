class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string tmp = "";
        for (int i = 0 ; i < s.size() ; i++){
            if (s[i] == ' '){
                if (tmp.size()){
                    st.push(tmp);
                    tmp = "";
                }
            }
            else {
                tmp += s[i];
            }
        }
        if (tmp.size()){
            st.push(tmp);
        }
        string ans = "";
        while (!st.empty()){
            tmp = st.top();
            st.pop();
            ans += tmp;
            if (st.size()) {
                ans += " ";
            }
        }
        return ans;
    }
};