class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int low = 0, same = 0, high = nums.size();
        for(auto n : nums) {
            if(n < pivot) 
                ++same; 
            else if(n > pivot)
                --high;
        }
        vector<int> res(nums.size());
        for(auto n : nums) {
            if(n < pivot)
                res[low++] = n; 
            else if(n == pivot) 
                res[same++] = n;
            else 
                res[high++] = n;
        }
        return res;
    }
};