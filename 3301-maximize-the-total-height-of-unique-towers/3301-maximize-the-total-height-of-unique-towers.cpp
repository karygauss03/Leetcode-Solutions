class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.rbegin(), maximumHeight.rend());
        long long ans = maximumHeight[0];
        for(int i = 1; i < maximumHeight.size(); i++) {
            maximumHeight[i] = min(maximumHeight[i], maximumHeight[i - 1] - 1);
            if(!maximumHeight[i]) return -1;
            ans += maximumHeight[i];
        }

        return ans;
    }
};