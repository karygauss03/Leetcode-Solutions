class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j, k = 1, res = 0;
        for (j = 0 ; j < nums.size() ; ++j) {
            if (nums[j] == 0) {
                k--;
            }
            while (k < 0) {
                if (nums[i] == 0) {
                    k++;
                }
                i++;
            }
            res = max(res, j - i);
        }
        return res;
    }
};