class Solution {
public:
    map<string, multiset<string>> graph;
    vector<string> res;
    void dfs(string vertex) 
    {
        while(!graph[vertex].empty())
        {
            string to_vertex = *(graph[vertex].begin());
            graph[vertex].erase(graph[vertex].begin());
            dfs(to_vertex);
        }
        res.push_back(vertex);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};