class Solution {
public:
    string sortVowels(string s) {
        map<char,int>mp; // for storing vowels
        set<char>st={'a','A','e','E','i','I','o','O','u','U'};
        for(auto it:s)
        {
            if(st.count(it))mp[it]++;
        }
        auto it=mp.begin();
        for(int i=0;i<s.size();i++)
        {
            if(!st.count(s[i]))continue;
            if(it->second==0)it++; 
            s[i]=it->first;
            it->second--;
        }
        return s;
    }
};