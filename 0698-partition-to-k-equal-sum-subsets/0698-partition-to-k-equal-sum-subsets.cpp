class Solution {
public:
    vector<int> masks;
    int dp[1<<16][17];
    bool solve(int n, int used, int k){
        if (k == 0 && used == ((1<<n) - 1)) return 1;
        if (k == 0 || used == ((1<<n) - 1)) return 0;
        if (dp[used][k] != -1) return dp[used][k];
        
        for (auto &mask : masks){
            if ((mask & used) == 0 && solve(n, used | mask, k - 1)){
                return dp[used][k] = 1;
            }
        }
        return dp[used][k] = 0;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (auto &x : nums) sum += x;
        if (sum % k) return false;
        int target = sum / k;
        for (int i = 0 ; i <(1<<n) ; i++){
            int cur = 0;
            for (int j = 0 ; j < n ; j++){
                if ((1<<j) & i){
                    cur += nums[j];
                }
            }
            if (cur == target) masks.push_back(i);
        }
        memset(dp, -1, sizeof dp);
        return solve(n, 0, k);
    }
};