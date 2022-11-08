class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        string ans = "";
        stack <char> st;
        for (int i=0;i<n;i++){
            if (st.empty()){
                st.push(s[i]);
            }
            else{
                char c = st.top();
                bool flag = 0;
                if (c!=s[i]){
                    if (c==tolower(s[i]) || c == toupper(s[i])){
                        st.pop();
                        flag = 1;
                    }
                }
                if (!flag){
                    st.push(s[i]);
                }
            }
        }
        while (!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};