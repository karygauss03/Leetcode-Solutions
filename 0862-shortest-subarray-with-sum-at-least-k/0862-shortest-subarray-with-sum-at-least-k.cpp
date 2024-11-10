class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long long sum = 0;
        int ans = INT_MAX;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if(sum >= k) {
                ans = min(ans, i + 1);
            }
            while (!pq.empty() && sum - pq.top().first >= k) {
                auto cur = pq.top();
                ans = min(ans, i - cur.second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        return ans != INT_MAX ? ans : -1;
    }
};