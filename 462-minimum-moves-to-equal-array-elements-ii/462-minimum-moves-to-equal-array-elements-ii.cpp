class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mid = nums[n/2];
        int ans = 0;
        for (int i = 0 ; i < n ; i++){
            ans += abs(mid-nums[i]);
        }
        return ans;
    }
};