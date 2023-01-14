class Solution {
public:
    vector<int> parent;
    vector<int> val;

    int find(int a){
        if(parent[a]<0){
            return a;
        }
        return parent[a]=find(parent[a]);
    }
    void Union(int a,int b){
        if(val[a]<val[b]){
           parent[b]=a;
        }else{
            parent[a]=b;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        
        parent.resize(26);
        val.resize(26);
        for(int i=0;i<26;i++){
            parent[i]=-1;
            val[i]=i;
        }
        for(int i=0;i<n;i++){
            int c1=s1[i]-'a';
            int c2=s2[i]-'a';
            int x=find(c1);
            int y=find(c2);
            if(x!=y){
                Union(x,y);
            }
        }
        string res="";
        for(int i=0;i<baseStr.size();i++){
            int c=baseStr[i]-'a';
            int root=find(c);
            char x=root+'a';
            res+=x;
        }
        return res;
    }
};