class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
       return is_sorted(nums.begin(),nums.end()) || is_sorted(nums.begin(),nums.end(),greater<int>());
    }
};