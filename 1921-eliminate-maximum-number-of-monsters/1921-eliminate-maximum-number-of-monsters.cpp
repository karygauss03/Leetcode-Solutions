class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> time_to_city(n);
        
        for (int i = 0; i < n; ++i) {
            time_to_city[i] = static_cast<double>(dist[i]) / speed[i];
        }
        
        sort(time_to_city.begin(), time_to_city.end());
        
        for (int i = 0; i < n; ++i) {
            if (time_to_city[i] <= i) {
                return i;
            }
        }
        
        return n;
    }
};