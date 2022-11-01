class Solution {
public:
    bool check(vector<int>& nums, int pos){
       int n = nums.size();
        long long cnt = 0;
        for (int i = 0 ; i < n ; i++){
            cnt += (nums[i] - pos);
            if (cnt > 0){
                return false;
            }
        }
        return true;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int l = INT_MAX, r = INT_MIN;
        for (int i = 0 ; i < n ; i++){
            l = min(l, nums[i]);
            r = max(r, nums[i]);
        }
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (check(nums, mid)){
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};