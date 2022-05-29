class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int j = 0, sum = 0;
        for (int i = 0 ; i < n; i++){
            sum += nums[i];
            while (sum >= target){
                ans = min(ans, i - j + 1);
                sum -= nums[j++];
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};