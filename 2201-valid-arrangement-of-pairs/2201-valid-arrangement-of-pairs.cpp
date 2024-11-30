class Solution {
public:
    map<int, list<int>> adj;
    map<int, int> in, out;
    vector<vector<int>> solve(vector<vector<int>>& p) {
        vector<vector<int>> ans;
        int src = -1;
        for (auto& o : out) {
            int cur = o.first;
            if (out[cur] == in[cur] + 1) {
                src = cur;
                break;
            }
        }
        if (src == -1) src = p[0][0];

        stack<int> cur_path;
        vector<int> path;
        cur_path.push(src);
        while (!cur_path.empty()) {
            int cur = cur_path.top();
            if (!adj[cur].empty()) {
                int v = adj[cur].front();
                adj[cur].pop_front();
                cur_path.push(v);
            }
            else {
                path.push_back(cur);
                cur_path.pop();
            }
        }

        reverse(path.begin(), path.end());

        for (int i = 1; i < path.size(); ++i) {
            ans.push_back({path[i - 1], path[i]});
        }

        return ans;
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        for (auto& p : pairs) {
            int src = p[0], dest = p[1];
            adj[src].push_back(dest);
            out[src]++, in[dest]++;
        }

        return solve(pairs);
    }
};