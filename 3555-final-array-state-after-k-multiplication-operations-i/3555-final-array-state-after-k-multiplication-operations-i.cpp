class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i], i});
        }
        while (k--) {
            auto cur = pq.top();
            pq.pop();
            cur.first *= multiplier;
            pq.push(cur);
        }
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            nums[cur.second] = cur.first;
        }
        return nums;
    }
};