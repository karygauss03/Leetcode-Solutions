class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for (auto& num : arr) freq[num]++;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (auto& [num, f] : freq) pq.push({f, num});

        while (k > 0) {
            auto& top = pq.top();
            int f = top[0], num = top[1];
            pq.pop();

            if (k >= f) {
                k -= f;
            }
            else {
                k = 0;
                pq.push({f - k, num});
            }
        }

        return pq.size();
    }
};