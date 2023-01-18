class Solution {
public:
    int kadane_algo(vector<int> &nums){
        int curr_sum = nums[0];
        int max_sum = nums[0];
        for(int i = 1; i < nums.size() ; i++){
            if(curr_sum >= 0){
                curr_sum += nums[i];
            }
            else{
                curr_sum = nums[i];
            }
            
            max_sum = max(max_sum , curr_sum);
        }
        return max_sum;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int res1 = kadane_algo(nums);
        if(res1 < 0){ // When all elements are negative
            return res1;
        }
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            nums[i] = -nums[i];
        }
        
        int res2 = kadane_algo(nums);
        int ans = sum + res2;
        return max(ans , res1);
    }
};