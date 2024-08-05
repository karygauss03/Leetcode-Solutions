class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int>sums;
        int MOD = 1e9 + 7;

        for(int i=0; i<n; i++)
        {
            int sum = 0;
            for(int j=i; j<n; j++)
            {
                sum += nums[j];
                sums.push_back(sum);
            }
        }

        sort(sums.begin(), sums.end());

        left = left-1;
        right = right-1;

        int ans = 0;
        for(int i=left; i<=right; i++)
        {
            ans = ans%MOD + sums[i]%MOD;
        }

        return ans%MOD;
    }
};