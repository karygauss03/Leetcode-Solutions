class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;
        int k = 1;
        for (int i = 1 ; i < nums.size() ; i++){
            if (nums[i] != nums[k - 1]){
                k++;
                nums[k - 1] = nums[i];
            }
        }
        return k;
    }
};