class Solution {
public:
    vector<int> adj[2005];
    bool vis[2005];
    bool isAncestor[2005];
    
    void fillGraph(vector<vector<int>>& preq){
        for (auto &edge : preq) {
            adj[edge[1]].push_back(edge[0]);
        }
    }
    
    bool isCycle(int &node) {
        vis[node] = true;
        isAncestor[node] = true;
        for (auto &neig : adj[node]) {
            if (isAncestor[neig] || (!vis[neig] && isCycle(neig))) return true;
        }
        isAncestor[node] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        fillGraph(prerequisites);
        memset(vis, false, sizeof vis);
        memset(isAncestor, false, sizeof isAncestor);
        for (int i = 0 ; i < numCourses ; ++i) {
            if (vis[i]) continue;
            if (adj[i].size() && isCycle(i)) return false;
        }
        return true;
    }
};