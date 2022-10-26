class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pref(n+1,0);
        for(int i=1;i<=n;i++)
            pref[i]=pref[i-1]+nums[i-1];
        map<int,int> mp;
        for(int i=2;i<=n;i++){
            mp[pref[i-2]%k]++;
            int curr=pref[i]%k;
            if(mp.count(curr))
                return true;
        }
        return false;
    }
};