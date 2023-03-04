class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0 ; i < 32 ; i++) {
            int cnt = 0;
            for (auto &num : nums) {
                if (num & (1<<i)) {
                    cnt++;
                }
            }
            ans += cnt * (n - cnt);
        }
        return ans;
    }
};