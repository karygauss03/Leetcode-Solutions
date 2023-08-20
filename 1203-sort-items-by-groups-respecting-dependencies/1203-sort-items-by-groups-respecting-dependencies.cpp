class Solution {
public:
    vector<int> dfs( vector<vector<int>>& adj, vector<int>& deg, int sz)
    {
      vector<int> res;
      function<void(int)> dfs=[&](int i){
        res.push_back(i);
        deg[i]=-1;
        for(int j:adj[i]){
            if (--deg[j]==0)
                dfs(j);
            }
        };

      for(int i=0; i<sz; i++)
          if (deg[i]==0)
            dfs(i);
      for(int i=0; i<sz; i++)
            if(deg[i]>0) return {};
      return res;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0; i<n; i++){
            if (group[i]==-1) group[i]=m++;
        }
        vector<vector<int>> adj_group(m) , adj_item(n);
        vector<int> deg_group(m, 0), deg_item(n, 0);
        for(int i=0; i<n; i++){
            int to_i=group[i];
            for(int from: beforeItems[i]){
                int from_j=group[from];
                if(to_i!=from_j){
                    adj_group[from_j].push_back(to_i);
                    deg_group[to_i]++;
                }
                adj_item[from].push_back(i);
                deg_item[i]++;
            }
        }
        vector<int> sort_group=dfs(adj_group, deg_group, m);
        vector<int> sort_item=dfs(adj_item, deg_item, n);
        if (sort_group.empty() || sort_item.empty()) return {};

        vector<vector<int>> item_gp(m);
        for(int i: sort_item)
            item_gp[group[i]].push_back(i);
        
        vector<int> ans;
        for(int i : sort_group) {
            for(int item : item_gp[i]) {
                ans.push_back(item);
            }
        }
        
        return ans;

    }
};