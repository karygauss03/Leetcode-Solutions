class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int evenCount = 0;
        for (auto &num : nums) {
            if (!(num & 1)) {
                ++evenCount;
            }
            if (!(evenCount & 1) && evenCount > 0) {
                return true;
            }
        }
        return false;
    }
};