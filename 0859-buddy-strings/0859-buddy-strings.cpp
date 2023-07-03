class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()) return false;

        if(s==goal){
            set<int> st;
            st.insert(s.begin(),s.end());
            return st.size()<s.length();
        }

        int i=0;
        int j=s.length()-1;
        while(i<j && s[i]==goal[i]){
            i++;
        }
        while(j>=0 && s[j]==goal[j]){
            j--;
        }
        
        swap(s[i],s[j]); 
        return s==goal; 
    }
};