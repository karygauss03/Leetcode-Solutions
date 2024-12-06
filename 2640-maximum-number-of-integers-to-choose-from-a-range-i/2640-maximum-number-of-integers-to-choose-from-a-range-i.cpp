class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        bitset<10001> bannedBits = 0;
        for (auto &num : banned) {
            bannedBits[num] = 1;
        }
        int cur_sum = 0, ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (!bannedBits[i]) {
                if (cur_sum + i > maxSum) return ans;
                ++ans;
                cur_sum += i;
            }
        }
        return ans;
    }
};