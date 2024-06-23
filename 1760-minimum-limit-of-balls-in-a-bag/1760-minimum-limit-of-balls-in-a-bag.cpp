class Solution {
public:
    bool ok(const vector<int>& nums, int maxOperations, int penalty) {
        int operations = 0;
        for (auto &num : nums) {
            if (num > penalty) {
                operations += (num - 1) / penalty;
                if (operations > maxOperations) {
                    return false;
                }
            }
        }
        return operations <= maxOperations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int l = 1, r = *max_element(nums.begin(), nums.end()), mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (mid == 0) {
                break;
            }
            if (ok(nums, maxOperations, mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
         }
        return l;
    }
};