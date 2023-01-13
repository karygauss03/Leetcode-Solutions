class Solution {
public:
    int dfs(vector<vector<int>>& x,int& mx,int i,string& s){
        if(x[i].size()==0) return 1;
        vector<int> e;
        int mx1=0,mx2=0;
        for(int j=0;j<x[i].size();j++){
            int a = dfs(x,mx,x[i][j],s);
            if(s[x[i][j]]==s[i]) a=0;
            if(a>mx1){
                mx2=mx1;
                mx1=a;
            }
            else if(a>mx2) mx2=a;
        }
        mx=max(mx,mx1+mx2+1);
        return mx1+1;
    }

    int longestPath(vector<int>& par, string s) {
        int n=par.size(),mx=1;
        vector<vector<int>> x(n,vector<int>());
        for(int i=0;i<n;i++){
            if(par[i]!=-1) x[par[i]].push_back(i);
        }
        dfs(x,mx,0,s);
        return mx;
    }
};