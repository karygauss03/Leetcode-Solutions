class Solution {
public:
    bool isPowerOfFour(int n) {
        int i = 1;
        long long x = 1;
        while (x != n && x < pow(2, 31)){
            x = x * 4;
        }
        if (x == n) return true;
        return false;
    }
};