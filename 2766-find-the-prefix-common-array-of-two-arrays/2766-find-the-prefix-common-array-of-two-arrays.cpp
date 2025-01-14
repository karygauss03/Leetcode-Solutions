class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> setA, setB, common;
        int n = A.size();
        vector<int> C(n, 0);
        long long aMask = 0LL, bMask = 0LL;
        for (int i = 0; i < n; ++i) {
            aMask |= (1LL<<A[i]);
            bMask |= (1LL<<B[i]);
            C[i] = __builtin_popcountll(aMask & bMask);
        }
        return C;
    }
};