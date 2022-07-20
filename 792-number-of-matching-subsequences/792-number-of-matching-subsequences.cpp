class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& v) {
        multiset<int> m[26];
        int i=0;
        for(char c:s)m[c-'a'].insert(i++);
        int ans=0;
        for(string s1:v){
                bool flag=true;
                int i=-1;
                for(int j=0;j<s1.length();j++){
                       auto it=m[s1[j]-'a'].lower_bound(i+1);
                        if(it==m[s1[j]-'a'].end()){
                                flag=false;
                                break;
                        }else{
                                i=*it;
                        }
                }
                if(flag)ans++;
        }
        return ans;
    }
};