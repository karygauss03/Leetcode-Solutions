class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long cnt = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            if (!nums[i]) {
                cnt++;
                ans += cnt;
            }
            else {
                cnt = 0;
            }
        }
        return ans;
    }
};