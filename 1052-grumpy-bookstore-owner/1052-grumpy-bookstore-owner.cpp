class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int cur_max = 0, n = customers.size();
        int prefix[n + 1];
        prefix[0] = 0;
        for (int i = 0; i < grumpy.size(); ++i) {
            if (!grumpy[i]) {
                cur_max += customers[i];
            }
            prefix[i + 1] = (grumpy[i] == 1) ? prefix[i] + customers[i] : prefix[i];
        }
        int ans = cur_max;
        for (int i = 0; i <= grumpy.size() - minutes; ++i) {
            ans = max(ans, cur_max + (prefix[i + minutes] - prefix[i]));
        }
        return ans;
    }
};