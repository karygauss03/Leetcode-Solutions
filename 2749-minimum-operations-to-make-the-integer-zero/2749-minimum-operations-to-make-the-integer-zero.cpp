class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if (num1 < num2)
            return -1;
        for (int k = 0 ; k <= 60 ; ++k) {
            long long sum = (long long)num1 - (long long)num2 * k;
            if (k <= sum && __builtin_popcountll(sum) <= k) {
                return k;
            }
        }
        return -1;
    }
};