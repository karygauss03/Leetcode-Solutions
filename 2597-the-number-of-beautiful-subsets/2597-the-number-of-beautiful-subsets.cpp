class Solution {
public:
    char freq[1001] = {0};
    int cnt = 0, n;
    void backtrack(int idx, vector<int>& nums, int k) {
        if (idx==n) {
            cnt++;
            return;
        }
        backtrack(idx+1, nums, k); // skip current number
        int x = nums[idx];
        if ((x - k < 0 || freq[x - k] == 0) &&
            (x + k > 1000 || freq[x + k] == 0)) {
            freq[x]++;
            backtrack(idx+1, nums, k); // include current number
            freq[x]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        backtrack(0, nums, k);
        return --cnt; // No empty subset
    }
};
