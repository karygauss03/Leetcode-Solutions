class Solution {
public:
    
    vector<bool> isSafe;
    
    void dfs(vector<vector<int>> &graph,int node,vector<bool> &vis,stack<int> &st){
        vis[node]=true;
        for(auto x:graph[node]){
            if(!vis[x]){
                dfs(graph,x,vis,st);
            }
        }
        st.push(node);
    }
    
    bool helper(vector<vector<int>> &graph,int node,vector<bool> &vis){
        vis[node]=true;
        if(isSafe[node]){
            return true;
        }
        int ans=1;
        for(auto x:graph[node]){
            if(!vis[x]){
                ans &= helper(graph,x,vis);
            }
            else{
                ans &=isSafe[x];
            }
        }
        isSafe[node]=ans;
        return ans;
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        isSafe.resize(n,false);
        vector<int> ans;
        stack<int> st;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph,i,vis,st);
            }
        }
        for(int i=0;i<n;i++){
            vis[i]=false;
        }
        while(!st.empty()){
            int top=st.top();
            st.pop();
            if(!vis[top]){
                helper(graph,top,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(isSafe[i])
                ans.push_back(i);
        }
        return ans;
    }
};