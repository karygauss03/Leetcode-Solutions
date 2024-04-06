class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        vector<int>idx;
        int n=s.size();
        int i;
        stack<pair<char,int>>st;
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push({s[i],i});
            }
            else if(s[i]==')')
            {
                if(st.empty())
                {
                    idx.push_back(i);
                }
                else
                {
                    st.pop();
                }
            }
        }
        string res="";
        int k=0;
        while(!st.empty())
        {
            idx.push_back(st.top().second);
            st.pop();
        }
        sort(idx.begin(),idx.end());
       
        for(i=0;i<n;i++)
        {
            if(k<idx.size() and idx[k]==i)
            {
                k++;
                continue;
            }
            res+=s[i];
        }
        return res;
        
    }
};