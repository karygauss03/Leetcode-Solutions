class Solution {
public:
    int kthGrammar(int n, int k) {
        int ans = 0, l = 0, r = (1 << n) - 1, mid;
        while (l < r) {
            mid = l +  (r - l) / 2;
            if (k - 1 <= mid) {
                r = mid;
            }
            else {
                l = ++mid;
                ans ^= 1;
            }
        }
        return ans;
    }
};