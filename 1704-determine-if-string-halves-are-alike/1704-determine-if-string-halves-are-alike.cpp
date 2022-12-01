class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt1=0,cnt2=0;
        set<char> se={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (int i=0;i<s.size()/2;i++){
            if (se.count(s[i])!=0) {
                cnt1++;
            }
        }
        for (int i=s.size()/2;i<s.size();i++){
            if (se.count(s[i])!=0) {
                cnt2++;
            }
        }
        return cnt1==cnt2;
    }
};