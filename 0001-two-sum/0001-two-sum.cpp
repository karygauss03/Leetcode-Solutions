class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> ma;
        for (int i = 0 ; i < n ; i++){
            if (ma.find(target - nums[i]) != ma.end()){
                return {i, ma[target - nums[i]]};    
            }
            ma[nums[i]] = i;
        }
        return {};
    }
};