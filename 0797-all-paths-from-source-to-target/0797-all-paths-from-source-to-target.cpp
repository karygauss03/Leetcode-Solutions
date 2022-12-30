class Solution {

public:

    vector<vector<int>> paths;

    vector<int> currPath;

    void dfs(int s, int d, vector<vector<int>>& graph){

        

        currPath.push_back(s);

        if(s==d){

            paths.push_back(currPath);

            currPath.pop_back();

            return;

        }

        for(auto neighbour : graph[s]){

            dfs(neighbour,d,graph); 

        }

        currPath.pop_back();

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        

        int n = graph.size();

        dfs(0,n-1,graph);

        return paths;

    }

};