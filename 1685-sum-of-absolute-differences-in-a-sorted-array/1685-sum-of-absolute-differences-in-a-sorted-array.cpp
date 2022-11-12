class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int pref[n];
        pref[0] = nums[0];
        for (int i = 1 ; i < n ; i++){
            pref[i] = pref[i - 1] + nums[i];
        }
        for (int i = 0 ; i < n ; i++){
            if (!i){
                ans.push_back(pref[n - 1] - pref[0] - (n - 1) * nums[i]);
            }
            else {
                int left = i * nums[i] - pref[i - 1];
                int right = pref[n - 1] - pref[i] - (n - i - 1) * nums[i];
                ans.push_back(left + right);
            }
        }
        return ans;
    }
};