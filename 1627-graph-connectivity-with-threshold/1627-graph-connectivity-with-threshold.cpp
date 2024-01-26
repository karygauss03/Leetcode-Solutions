class Solution {
public:

    vector<int> graph[10001];
    int parent[10001], rank[10001];
    
	int find(int n){
        if(parent[n]<0) return n;
        return parent[n]=find(parent[n]);
    }
    
    void merge(int pu, int pv){
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
            rank[pu]+=rank[pv];
        }else{
            parent[pu]=pv;
            rank[pv]+=rank[pu];
        }
    }
    
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        for(int i=0;i<=n;i++) parent[i]=-1;
        
        for(int u=threshold+1;u<n+1;u++){
            for(int v=2*u;v<n+1;v+=u){
                int pu=find(u), pv=find(v);
                
                if(pu!=pv){
                    merge(pu,pv);
                }
            }
        }
        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0], v=queries[i][1];
            int pu=find(u), pv=find(v);
            
            ans.push_back(pu==pv);
        }
        return ans;
    }
};