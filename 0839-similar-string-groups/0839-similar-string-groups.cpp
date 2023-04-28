class union_set{
public:
    vector<int> arr;
    union_set(int n):arr(n){
        for(int i= 0;i<n;i++){
            arr[i] = i;
        }
    }
    int find(int x){
        if(x==arr[x]){
            return x;
        }
        else{
            return arr[x] = find(arr[x]);
        }
    }
    void unite(int s,int p){
        arr[find(s)] = find(p);
    }
};

class Solution {
public:
    bool func(const string& a,const string& b){
        if(a.size()!=b.size())
            return false;
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i])
                if (++diff > 2) return false;
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        set<int>st;
        union_set group(strs.size());
        for(int i= 0;i<strs.size();++i){
            for(int j = i+1;j<strs.size();++j)
            {
                if(group.find(i)!=group.find(j)&&func(strs[i],strs[j])){
                    group.unite(i,j);
                }
            }
        }
        for(int i = 0;i<strs.size();++i){
            st.insert(group.find(i));
        }
        return st.size();
    }
};