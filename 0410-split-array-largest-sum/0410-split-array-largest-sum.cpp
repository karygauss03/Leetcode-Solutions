class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        
        int n = nums.size();
        int left = 0, right = 0;
        //Left will store the maximum element in the array which is the minimum ans value
        //Right will store the sum of all elements in the array which is the maximum ans value
        for (int i = 0 ; i < n ; i++){
            left = max(left, nums[i]);
            right += nums[i];
        }
        
        int ans = 0, mid, cnt, tempSum;
        while (left <= right){
            mid = left + (right - left) / 2;
            cnt = 0, tempSum = 0;
            
            for (int i = 0 ; i < n ; i++){
                if (tempSum + nums[i] <= mid){
                    tempSum += nums[i];
                }
                else {
                    cnt++;
                    tempSum = nums[i];
                }
            }
            cnt++;
            if (cnt <= m){
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
    
};