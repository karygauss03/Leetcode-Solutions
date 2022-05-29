class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> ma;
        
        for (int i = 0 ; i < n; i ++){
            if (ma.find(nums[i]) != ma.end()){
                return vector<int> {ma[nums[i]], i};
            }
            else {
                ma[target - nums[i]] = i;
            }
        }
        return vector<int> {0, 0};
    }
};