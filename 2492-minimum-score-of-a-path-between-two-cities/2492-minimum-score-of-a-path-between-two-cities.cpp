class Solution {
public:
    vector<vector<pair<int, int>>>adj;
    int minScore(int n, vector<vector<int>>& roads) {
        adj.resize(n + 1);
        
        for(vector<int>edge : roads){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<long>dist(n + 1, INT_MAX);
        dist[1] = 0;
        priority_queue<pair<int, int>>pq;
        pq.push({0, 1});
        long ans = INT_MAX;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int node = top.second;
            for(pair<int, int> child : adj[node]){
                if(dist[child.first] > -dist[node] + child.second){
                    dist[child.first] = -dist[node] + child.second;
                    ans = min(ans, (long)child.second);
                    pq.push({-dist[child.first], child.first, });
                }
            }
        }
        return ans;
    }
};