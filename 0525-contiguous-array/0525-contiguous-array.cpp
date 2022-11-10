class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        map<int, int> ma;
        ma[0] = -1;
        for (int i = 0 ; i < n ; i++){
            if (!nums[i]){
                nums[i] = -1;
            }
            if (i){
                nums[i] += nums[i - 1];
            }
            if (ma.find(nums[i]) != ma.end()){
                ans = max(ans, i - ma[nums[i]]);
            }
            else {
                ma[nums[i]] = i;
            }
        }
        return ans;
    }
};