class Solution {
public:
    int pivotInteger(int n) {
        int ans = (n * n + n ) /2;
        int sq = sqrt(ans);
        if(sq * sq == ans)return sq;
        else return -1;
    }
};
