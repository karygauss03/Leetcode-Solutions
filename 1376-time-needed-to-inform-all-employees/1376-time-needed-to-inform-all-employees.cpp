class Solution 
{
    public:
    int dfs(int n,int curr_node,vector<int> &manager,vector<int> &informTime,vector<vector<int>> &childs)
    {
        int ans=0,time=informTime[curr_node];
        
        for(int child:childs[curr_node])
            ans=max(ans,dfs(n,child,manager,informTime,childs));
        
        time+=ans;
        return time;
    }
    
    int numOfMinutes(int n,int headID,vector<int> &manager,vector<int> &informTime)
    {
        vector<vector<int>> childs(n);
        
        for(int i=0;i<n;i++)
        {
            if(i!=headID)
            childs[manager[i]].push_back(i);
        }
        return dfs(n,headID,manager,informTime,childs);    
    }
};