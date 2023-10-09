class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {  
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            }
            else if (nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid, r = mid;
                while (l >= 0 && nums[l] == target) {
                    --l;
                }
                while (r < nums.size() && nums[r] == target) {
                    ++r;
                }
                return {++l, --r};
            }
        }
        return {-1, -1};
    }
};