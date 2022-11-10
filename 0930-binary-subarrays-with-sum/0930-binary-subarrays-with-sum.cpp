class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        const int N = 3 * 1e4 + 5;
        int ans = (nums[0] == goal);
        int ma[N];
        memset(ma, 0, sizeof ma);
        ma[0] = 1;
        ma[nums[0]]++;
        for (int i = 1 ; i < n ; i++){
            nums[i] += nums[i - 1];
            if (nums[i] >= goal){
                ans += ma[nums[i] - goal];
            }
            ma[nums[i]]++;
        }
        return ans;
    }
};