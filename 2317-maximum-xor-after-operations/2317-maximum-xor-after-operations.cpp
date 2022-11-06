class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        //nums[i] = nums[i] & (nums[i] ^ x) => the result will <= nums[i] because of AND operation
        //we are turning OFF some ON bits (we cannot ON OFF's bits)
        //The goal is to maximize the XOR of all numbers
        //We will try to either OFF or ON all bits
        //The answer will be the OR of all numbers
        int ans = 0;
        for (int i = 0 ; i < nums.size() ; i++){
            ans |= nums[i];
        }
        return ans;
    }
};