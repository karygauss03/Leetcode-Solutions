class Solution {
    int hoursRequired(const vector<int> &piles, int k){
        int h = 0;
        if(k == 0) return INT_MAX;
        for(int i : piles){
            if(i % k != 0){
                h++;
            }
            h += (i / k);
        }
        return h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        long long sum = 0;
        int mx = 0;
        for(int i = 0; i < piles.size(); i++){
            sum += piles[i];
            mx = max(mx, piles[i]);
        }
        int l = sum / H, r = mx, ans;
        while(l < r){
            int mid = l + (r - l) / 2;
            int ans = hoursRequired(piles, mid);
            if(ans > H){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
};