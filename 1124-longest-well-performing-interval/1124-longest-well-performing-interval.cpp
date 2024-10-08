class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans = 0, n = hours.size(), count = 0;
        for (int i = 0; i < n; ++i) {
            hours[i] = hours[i] > 8 ? 1 : -1;
        }
        int sum = 0;
        unordered_map<int, int> prev;
        for (int i = 0; i < n; ++i) {
            sum += hours[i];
            if (prev.find(sum) == prev.end()) {
                prev[sum] = i;
            }
            if (sum > 0) {
                ans = i + 1;
            }
            else if (prev.find(sum - 1) != prev.end()) {
                ans = max(ans, i - prev[sum - 1]);
            }
        }
        return ans;
    }
};