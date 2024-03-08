class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[105];
        for (auto& num : nums) {
            freq[num]++;
        }
        int mx = 0;
        for(auto &f : freq) {
            mx = max(mx, f);
        }
        int ans = 0;
        for (auto &f : freq) {
            if (f == mx) {
                ans += mx;
            }
        }
        return ans;
    }
};