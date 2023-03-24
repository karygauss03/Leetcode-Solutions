class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> road(n), adj(n);
        for(auto i : connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            road[i[0]].push_back(i[1]);
        }
        queue<int> q;
        q.push(0);
        int cnt = 0;
        vector<int> vis(n, 0);
        while(!q.empty())
        {
            int node = q.front();
            vis[node]=1;
            q.pop();
            for(auto i : adj[node]){
                if(!vis[i])
                {
                    q.push(i);
                    for(auto j:road[i])
                        if(j == node) cnt--;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};