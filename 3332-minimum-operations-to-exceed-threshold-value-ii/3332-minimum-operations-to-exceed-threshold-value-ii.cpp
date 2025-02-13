class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (auto& elt : nums) pq.push(elt);
        while (pq.size() >= 2 && pq.top() < k) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(2 * x + y);
            ++ans;
        }
        return ans;
    }
};