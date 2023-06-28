class Solution {
public:
    vector<pair<int, double>> adj[10005];
    priority_queue<pair<double, int>> pq;
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for (int i = 0 ; i < edges.size() ; ++i) {
            adj[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        pq.push({1.0, start});
        vector<double> probabilities(n + 1, 0.0);
        probabilities[start] = 1.0;
        while (!pq.empty()) {
            pair<double, int> topElement = pq.top();
            pq.pop();
            if (topElement.second == end) {
                continue;
            } 
            for (auto &u : adj[topElement.second]) {
                if (probabilities[u.first] < topElement.first * u.second) {
                    probabilities[u.first] = topElement.first * u.second;
                    pq.push({probabilities[u.first], u.first});
                }
            }
        }
        return probabilities[end];
    }
};