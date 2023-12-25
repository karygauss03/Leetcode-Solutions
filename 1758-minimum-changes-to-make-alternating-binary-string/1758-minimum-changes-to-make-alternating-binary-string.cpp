class Solution {
public:
    int minOperations(string s) {
        int res = 0, n = s.length();
        for (int i = 0; i < n; ++i)
            if (s[i] - '0' != i % 2)
                res++;
        return min(res, n - res);
    }
};