class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for(int i = 0; i < nums.size(); ++i) sum += nums[i];
        for(int i = nums.size()-1; i >= 2; --i){
            sum -= nums[i];
            if(nums[i] < sum) return sum + (long long)nums[i];
        }
        return -1;
    }
};