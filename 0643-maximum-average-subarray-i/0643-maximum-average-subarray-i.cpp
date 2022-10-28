class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double mx = 0;
        for (int i = 0 ; i < k ; i++){
            mx += (double)nums[i];
        }
        double cur = mx;
        for (int i = k ; i < nums.size() ; i++){
            cur -= (double)nums[i - k];
            cur += (double)nums[i];
            mx = max(cur, mx);
        }
        return mx/(double)k;
    }
};