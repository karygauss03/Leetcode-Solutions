class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end()), ans = 0;
        vector<int> freq(nums.size() + mx + 1, 0);
        for (auto &n : nums) {
            freq[n]++;
        }
        for (int i = 0; i < freq.size(); ++i) {
            if (freq[i] <= 1) {
                continue;
            }
            freq[i + 1] += (freq[i] - 1);
            ans += (freq[i] - 1);
        }
        return ans;
    }
};