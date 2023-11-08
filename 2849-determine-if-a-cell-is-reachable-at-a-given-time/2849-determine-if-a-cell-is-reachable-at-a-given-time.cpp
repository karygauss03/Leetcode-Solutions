class Solution {
public:
    int Chebyshev(int sx, int sy, int fx, int fy){
        return max(abs(sx-fx), abs(sy-fy) );
    }
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int d=Chebyshev(sx, sy, fx, fy);
        return d>0 ? t>=d: t!=1;
    }
};