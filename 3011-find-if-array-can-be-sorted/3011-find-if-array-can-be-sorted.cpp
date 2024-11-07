class Solution {
public:
    bool canSortArray(vector<int>& a) {
        int mn = a[0], mx = a[0], bitCount = __builtin_popcount(a[0]), prevMx = INT_MIN, currentBitCount;
        for (int i = 1; i < a.size(); ++i) {
            currentBitCount = __builtin_popcount(a[i]);
            if (currentBitCount == bitCount) {
                mn = min(a[i], mn);
                mx = max(a[i], mx);
            }
            else {
                if (mn < prevMx) {
                    return false;
                }
                prevMx = mx;
                mx = a[i], mn = a[i], bitCount = currentBitCount;
            }
        }
        if (mn < prevMx) {
            return false;
        }
        return true;
    }
};