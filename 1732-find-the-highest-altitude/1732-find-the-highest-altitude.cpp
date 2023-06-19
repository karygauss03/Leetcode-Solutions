class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int cur = 0;
        for (auto &g : gain){
            cur += g;
            ans = max(ans, cur);
        }
        return ans;
    }
};