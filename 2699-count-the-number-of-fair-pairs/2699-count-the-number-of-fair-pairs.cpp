class Solution {
private:
    long long binarySearch(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        long long res = 0;
        while (l < r) {
            int curSum = nums[l] + nums[r];
            if (curSum < target) {
                res += r - l;
                ++l;
            }
            else {
                --r;
            }
        }
        return res;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return binarySearch(nums, upper + 1) - binarySearch(nums, lower);
    }
};