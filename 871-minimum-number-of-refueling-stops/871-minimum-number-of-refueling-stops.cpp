class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> stations) {
        priority_queue<int> visited;
        int fuel = startFuel;
        int previous_position = 0;
        int res = 0;
        stations.push_back({target, 0});
        for (const auto& v : stations) {
            const int position = v[0], station_fuel = v[1];
            const int fuel_required = position - previous_position;
            while (fuel < fuel_required && !empty(visited)) {
                fuel += visited.top();
                visited.pop();
                ++res;
            }
            if (fuel < fuel_required) {
                return -1;
            }
            fuel -= fuel_required;
            visited.push(station_fuel);
            previous_position = position;
        }
        return res;
    }
};