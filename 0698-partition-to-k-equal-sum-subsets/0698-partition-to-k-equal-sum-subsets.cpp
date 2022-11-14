class Solution {
public:
    bool vis[17];
    int n;
    bool solve(vector<int>& nums, int i, int cur, int target, int k){
        if (k == 1) return 1;
        if (cur == target) return solve(nums, 0, 0, target, k - 1);
        for (int j = i + 1 ; j < n ; j++){
            if (vis[j] || cur + nums[j] > target) continue;
            vis[j] = true;
            if (solve(nums, j, cur + nums[j], target, k)) return true;
            vis[j] = false;
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        int sum = 0;
        for (auto &num : nums) sum += num;
        if (sum % k) return false;
        memset(vis, 0, sizeof vis);
        return solve(nums, 0, 0, sum / k, k);
    }
};