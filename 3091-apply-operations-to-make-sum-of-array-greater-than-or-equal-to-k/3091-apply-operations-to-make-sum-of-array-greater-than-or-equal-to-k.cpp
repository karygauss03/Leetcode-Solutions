class Solution {
public:
    int minOperations(int k) {
        int x = sqrt(k);
        return x + (k - 1) / x - 1;
    }
};