class Solution {
public:
    int n;
    int solve(vector<int>& nums, int L, int R){
        int ans = 0;
        vector<int> pref(n + 1), suff(n + 1);
        for (int i = 0, j = n - 1, cur_left = 0, cur_right = 0; i < n , j >= 0 ; i++ , j--){
            cur_left += nums[i];
            pref[i + 1] = max(pref[i], cur_left);
            cur_right += nums[j];
            suff[j] = max(suff[j + 1], cur_right);
            if (i + 1 >= L) cur_left -= nums[i + 1 - L];
            if (i + 1 >= R) cur_right -= nums[j + R - 1];
            
        }
        for (int i = 0 ; i < n ; i++){
            ans = max(ans, pref[i] + suff[i]);
        }
        return ans;
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        n = nums.size();
        vector<int> pref(n);
        pref[0] = nums[0];
        for (int i = 1 ; i < n ; i++) pref[i] = pref[i - 1] + nums[i];
        vector<int> suff(n);
        suff[n - 1] = nums[n - 1];
        for (int i = n - 2 ; i >= 0 ; i--) suff[i] = suff[i + 1] + nums[i];
        // Case 1: firstLen before secondLen
        //Case2: secondLen before firstLen
        return max(solve(nums, firstLen, secondLen), solve(nums, secondLen, firstLen));
    }
};