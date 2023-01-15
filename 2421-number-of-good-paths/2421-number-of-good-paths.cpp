class Solution {

private:
    
    void Union(int node1, int node2, vector<int>&parent){
        
        int par1 = findParent(node1,parent);
        int par2 = findParent(node2, parent);
        
        parent[par1] = min(par1, par2);
        parent[par2] = min(par1, par2);
    }
    
    int findParent(int node, vector<int>&parent){
        if(parent[node] == node){
            return node;
        }
        
        return parent[node] = findParent(parent[node], parent);
    }
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
        int n = vals.size();
        int ans = 0;
        map<int,vector<int>>values;
        vector<int>adj[n];
        vector<int>parent(n, -1);
        
        for(int index = 0; index < edges.size(); index++){
            
            adj[edges[index][1]].push_back(edges[index][0]);
            adj[edges[index][0]].push_back(edges[index][1]);
           
        }
        
        for(int index= 0; index <n ; index ++){
            
            values[vals[index]].push_back(index);
        }
  
        
        for(auto node:values){
            
            for(auto curr: values[node.first]){
                parent[curr] = curr;

                for(auto num:adj[curr]){
                    if(parent[num]!= -1){
                        Union(curr, num, parent);
                    }
                }
            }
            map<int,int>par;
             for(auto curr: values[node.first]){
               int val = findParent(curr, parent);
                 par[val]++;
            }
            
            for(auto num:par){
                ans += num.second*(num.second-1)/2;
            }
        }
        
        
        return ans+n;
        
    }
};