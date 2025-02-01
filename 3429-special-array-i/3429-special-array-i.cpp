class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if (nums.size() == 2) return nums[0] % 2 != nums[1] % 2;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] % 2 == nums[i + 1] % 2) return false;
        }
        return true;
    }
};