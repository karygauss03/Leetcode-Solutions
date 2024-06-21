class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int cur_max = 0;
        for (int i = 0; i < grumpy.size(); ++i) {
            if (!grumpy[i]) {
                cur_max += customers[i];
            }
        }
        int ans = cur_max;
        for (int i = 0; i <= grumpy.size() - minutes; ++i) {
            int tmp = cur_max;
            for (int j = i; j < i + minutes; ++j) {
                // cout << j << " ";
                if (grumpy[j]) {
                    tmp += customers[j];
                }
            }
            // cout << endl;
            ans = max(ans, tmp);
        }
        return ans;
    }
};