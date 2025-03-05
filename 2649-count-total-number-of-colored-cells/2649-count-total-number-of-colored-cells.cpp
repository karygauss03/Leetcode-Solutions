class Solution {
public:
    long long coloredCells(int n) {
        return 1LL + (long long)n * (long long)(n - 1) * 2LL;
    }
};