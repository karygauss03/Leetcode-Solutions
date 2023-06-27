class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0, cnt[10] = {};
        for (int i = 0 ; i < nums.size() ; ++i) {
            for (int j = 1 ; j < 10 ; ++j) {
                if (__gcd(j, nums[i] % 10) == 1) {
                    ans += cnt[j];
                }
            }
            while (nums[i] >= 10) {
                nums[i] /= 10;
            }
            ++cnt[nums[i]];
        }
        return ans;
    }
};