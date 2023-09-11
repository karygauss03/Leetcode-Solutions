class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        
        int n = groupSizes.size();
        
        int vis[n];
        
        memset(vis,0,sizeof(vis));
        
        for (int i = 0 ; i < n ; i++){
            int sz = groupSizes[i];
            vector<int> cur;
            if (vis[i] == 1)
                continue;
            vis[i] = 1;
            cur.push_back(i);
            int j = i+1, cur_sz = 1;
            while (j<n && cur_sz < sz){
                if (vis[j] == 0 && groupSizes[j] == sz){
                    vis[j] = 1;
                    cur.push_back(j);
                    cur_sz++;
                }
                j++;
            }
            ans.push_back(cur);
        }
        return ans;
        
    }
};