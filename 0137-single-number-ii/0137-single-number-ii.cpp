class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int appearOnce = 0, appearTwice = 0;
        for(int index = 0; index < nums.size(); index++) {
            appearOnce = (appearOnce ^ nums[index]) & ~(appearTwice);
            appearTwice = (appearTwice ^ nums[index]) & ~(appearOnce);
        }
        return appearOnce;
    }
};