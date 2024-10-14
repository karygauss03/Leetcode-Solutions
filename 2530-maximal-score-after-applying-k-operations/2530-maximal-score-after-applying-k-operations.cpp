class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> maxHeap;
        for (auto& n : nums) {
            maxHeap.push(n);
        }
        int curMax;
        while (k--) {
            curMax = maxHeap.top();
            maxHeap.pop();
            ans += curMax;
            maxHeap.push((curMax + 2) / 3);
        }
        return ans;
    }
};