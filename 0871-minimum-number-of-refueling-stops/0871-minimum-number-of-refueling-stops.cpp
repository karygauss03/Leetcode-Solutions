class Solution {
public:
    int minRefuelStops(int target, int fuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int ans = 0, prev = 0;
        stations.push_back({target, 0});
        for (auto& station: stations) {
            int pos = station[0], cap = station[1];
            int fuelRequired = pos - prev;
            while (!pq.empty() && fuel < fuelRequired) {
                fuel += pq.top();
                pq.pop();
                ++ans;
            }
            if (fuel < fuelRequired) {
                return -1;
            }
            fuel -= fuelRequired;
            pq.push(cap);
            prev = pos;
        }
        return ans;
    }
};