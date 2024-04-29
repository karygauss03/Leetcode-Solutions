class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int allXor = 0;
        for (auto& num: nums) {
            allXor ^= num;
        }
        
        return __builtin_popcount(allXor ^ k);
    }
};