class Solution {
public:
    char code[500000];
    int vis[500000];
    bool isIsomorphic(string s, string t) {
        memset(code,'&',sizeof(code));
        memset(vis,0,sizeof(vis));
        int n = s.size();
        for (int i=0;i<n;i++){
            if (code[s[i]] == '&' && vis[t[i]] == 0){
                code[s[i]] = t[i];
                vis[t[i]] = 1;
            }
            else if (code[s[i]] != t[i]){
                return false;
            }
        }
        return true;
    }
};