class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int pref[n];
        pref[0] = nums[0];
        for (int i = 1 ; i < n ; i++){
            pref[i] = nums[i] ^ pref[i - 1];
        }
        vector<int> ans;
        while (n){
            ans.push_back(pref[n - 1] ^ (1<<maximumBit) - 1);
            n--;
        }
        return ans;
    }
};