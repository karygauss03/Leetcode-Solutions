class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLength = 0;
        for (int start = 0; start < nums.size(); start++) {
            int currLength = 1;
            for (int pos = start + 1; pos < nums.size(); pos++) {
                if (nums[pos] > nums[pos - 1]) {
                    currLength++;
                } else {
                    break;
                }
            }
            maxLength = max(maxLength, currLength);
        }

        for (int start = 0; start < nums.size(); start++) {
            int currLength = 1;
            for (int pos = start + 1; pos < nums.size(); pos++) {
                if (nums[pos] < nums[pos - 1]) {
                    currLength++;
                } else {
                    break;
                }
            }
            maxLength = max(maxLength, currLength);
        }

        return maxLength;
    }
};