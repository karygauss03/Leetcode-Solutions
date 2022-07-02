class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {

        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());


        long long maxW = 0;
        long long maxL = 0;

        maxW = max(hc[0] - 0, h - hc[hc.size() - 1]);
        for(int i = 0; i < hc.size() - 1; i++){
            long long diff = hc[i + 1] - hc[i];
            maxW = max(maxW, diff);
        }

        maxL = max(vc[0] - 0, w - vc[vc.size() - 1]);
        for(int i = 0; i < vc.size() - 1; i++){
            long long diff = vc[i + 1] - vc[i];
            maxL = max(maxL, diff);
        }

        long long ans = maxW * maxL;
        return (ans % MOD);
    }
};