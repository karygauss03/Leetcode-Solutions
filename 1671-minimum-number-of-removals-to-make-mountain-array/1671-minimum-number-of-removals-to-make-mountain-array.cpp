class Solution {
private:
    vector<int> LIS(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        vector<int> bucket = {nums[0]};
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > bucket.back()) {
                bucket.push_back(nums[i]);
            }
            else {
                int low = lower_bound(bucket.begin(), bucket.end(), nums[i]) - bucket.begin();
                bucket[low] = nums[i];
            }
            ans[i] = bucket.size();
        }
        
        return ans;
    }

public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        if (n == 3) {
            return 0;
        } 
        
        vector<int> lis = LIS(nums);
        reverse(nums.begin(), nums.end());
        vector<int> revLis = LIS(nums);
        reverse(revLis.begin(), revLis.end());
        
        int ans = n;
        for (int i = 0; i < n; ++i) {
            if (lis[i] > 1 && revLis[i] > 1) {
                ans = min(ans, n - lis[i] - revLis[i] + 1);
            }
        }
        return ans;

    }
};