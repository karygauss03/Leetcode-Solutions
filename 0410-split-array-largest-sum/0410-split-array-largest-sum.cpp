class Solution {
public:
    int get_min_subarrays(vector<int>&nums, int mid){
        int sum = 0, min_subbarays = 1;
        for(auto &x : nums){
            if (x + sum <= mid){
                sum += x;
            }
            else {
                sum = x;
                min_subbarays++;
            }
        }
        return min_subbarays;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int right = 0, left = 0;
        for (auto &x : nums){
            left = max(left, x);
            right += x;
        }
        int ans = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            int cur_min = get_min_subarrays(nums, mid);
            if (cur_min <= k){
                right = mid - 1;
                ans = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};