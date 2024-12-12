class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for (auto& gift : gifts) {
            pq.push(gift);
        }
        while (k--) {
            int cur = pq.top();
            pq.pop();
            pq.push((int)sqrt(cur));
        }
        long long ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};