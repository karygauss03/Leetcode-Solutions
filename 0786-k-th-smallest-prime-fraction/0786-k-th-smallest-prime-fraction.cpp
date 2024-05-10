class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, pair<int, int>>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({-1.0 * (double)arr[i] / (double)arr[n - 1], {i, n - 1}});
        }
        
        while (--k) {
            auto cur = pq.top().second;
            pq.pop();
            cur.second--;
            pq.push({-1.0 * (double)arr[cur.first] / (double)arr[cur.second], {cur.first, cur.second}});
        }
        
        auto res = pq.top().second;
        return {arr[res.first], arr[res.second]};
    }
};