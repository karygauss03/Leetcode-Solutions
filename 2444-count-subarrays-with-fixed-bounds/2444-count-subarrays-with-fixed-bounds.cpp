class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        bool minFound = false, maxFound = false;
        int st = 0, minSt =0, maxSt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                minFound = false;
                maxFound = false;
                st = i + 1;
                continue;
            }
            if (nums[i] == minK) {
                minFound = true;
                minSt = i;
            }
            if (nums[i] == maxK) {
                maxFound = true;
                maxSt = i;
            }
            if (maxFound && minFound) {
                ans += (min(minSt, maxSt) - st + 1);
            }
        }
        return ans;
    }
};
