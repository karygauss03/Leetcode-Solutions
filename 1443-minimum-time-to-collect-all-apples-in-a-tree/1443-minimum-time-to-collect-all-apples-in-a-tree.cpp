class Solution {
public:
    int dfs(vector<int> adj[],int n,int node,int prev,vector<bool> &hasApple){
        int tree = 0;
        for(auto &ele:adj[node]){
            if(ele!=prev){
                int subtree = dfs(adj,n,ele,node,hasApple);
                tree += subtree;
            }
        }
        if(adj[node].size()==1 && node!=0){
            tree += hasApple[node];
        }
        else if(node!=0){
            if(tree!=0 || hasApple[node]) tree++; 
        }
        return tree;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple){
        int sz = hasApple.size();
        vector<int> adj[sz];
        for(auto &ele:edges){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        int req = dfs(adj,n,0,-1,hasApple);
        return 2*req;
    }
};