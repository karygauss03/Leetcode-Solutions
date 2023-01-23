class Solution {
    
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==1) return trust[0][1];
        
        vector<int> vis(n+1,0);
        map<int,int> mp;
        for(int i=0;i<trust.size();i++){
            int u = trust[i][0];
            vis[u] = 1;
            mp[u]++;
            mp[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if(vis[i] == 0) {
                if(mp[i] == n-1) return i;
            }
        }
        
        return -1;
    }
};