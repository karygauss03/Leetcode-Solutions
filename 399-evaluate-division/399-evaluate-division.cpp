class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> adj_list;
    vector<double> ans;
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for(int i = 0; i < equations.size(); i++)
        {
            adj_list[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
            adj_list[equations[i][1]].push_back(make_pair(equations[i][0], 1.0/values[i]));
        }
        
        for(int i = 0; i < queries.size(); i++)
        {
            unordered_set<string> visit;
            string src = queries[i][0];
            string dest = queries[i][1];
            
            if(!dfs(src, dest, 1.0, visit))
            {
                ans.push_back(-1.0);
            }
        }
        
        return ans;
    }
    
    bool dfs(string src, string dest, double val,unordered_set<string> visit)
    {
        if(visit.find(src) != visit.end())
        {
            return false;
        }
        
        if(adj_list.find(src) == adj_list.end() ||
          adj_list.find(dest) == adj_list.end())
        {
            ans.push_back(-1.0);
            return true;
        }
        
        if(src == dest)
        {
            ans.push_back(val);
            return true;
        }
        
        visit.insert(src);
        
        for(auto n: adj_list[src])
        {
            string newnode = n.first;
            double amt = n.second;
            if(dfs(newnode, dest, val*amt, visit))
            {
                return true;
            }
        }
        
        return false;
    }
    
};