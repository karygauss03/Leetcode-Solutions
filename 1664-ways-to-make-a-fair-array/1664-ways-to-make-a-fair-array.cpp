class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        int sum_odd[n], sum_even[n];
        sum_odd[0] = 0, sum_even[0] = nums[0];
        for (int i = 1 ; i < n ; i++){
            if (i&1){
                sum_odd[i] = sum_odd[i - 1] + nums[i];
                sum_even[i] = sum_even[i - 1];
            }
            else {
                sum_even[i] = sum_even[i - 1] + nums[i];
                sum_odd[i] = sum_odd[i - 1];
            }
        }
        int ans = 0;
        if (sum_even[n - 1] - sum_even[0] == sum_odd[n - 1]) ans++;//if the first element should be removed
        for (int i = 1 ; i < n - 1 ; i++){
            int even = sum_even[n - 1] - sum_even[i];
            int odd = sum_odd[n - 1] - sum_odd[i];
            if (even + sum_odd[i - 1] == odd + sum_even[i - 1]) ans++; //if i-th element should be removed
        }
        if (sum_even[n - 2] == sum_odd[n - 2]) ans++; //if last value should be removed
        return ans;
    }
};