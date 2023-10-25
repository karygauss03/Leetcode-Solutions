class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        if (!(k & 1)) {
            return kthGrammar(n - 1, k / 2) == 0 ? 1 : 0;
        }
        else {
            return kthGrammar(n - 1, (k + 1) / 2) == 0 ? 0 : 1;
        }
    }
};