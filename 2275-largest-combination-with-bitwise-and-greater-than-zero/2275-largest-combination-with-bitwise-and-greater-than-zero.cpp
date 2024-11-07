class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for (int i = 0; i < 24; ++i) {
            int cur = 0;
            for (int j = 0 ; j < candidates.size(); ++j) {
                if (candidates[j] & (1 << i)) {
                    ++cur;
                }
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};