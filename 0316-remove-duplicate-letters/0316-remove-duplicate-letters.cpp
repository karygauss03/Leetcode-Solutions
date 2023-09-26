class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        unordered_map<char, int> freq;
        int n = s.size();
        for (int i = 0 ; i < n; i++){
            freq[s[i]] = i;
        }
        unordered_set<char> x;
        string ans="";
        int i=0;
        while(i<s.size()) {
              while(ans!="" && ans.back()>s[i] && freq[ans.back()]>=i && !x.count(s[i])) {
                  x.erase(ans.back());
                  ans.pop_back();
              }
              if(!x.count(s[i])) {
                ans.push_back(s[i]);
                x.insert(s[i]);
              }
            i++;
        }
     return ans;
    }
};