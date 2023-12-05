class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 1;
        multiset<int> min_maxTrack;
        min_maxTrack.insert(nums[0]);
        int l = 0;
        for (int r = 1 ; r < nums.size() ; ++r) {
            min_maxTrack.insert(nums[r]);
            if (*min_maxTrack.rbegin() - *min_maxTrack.begin() <= limit) {
                ans = max(ans, r - l + 1);
                continue;
            }
            while(*min_maxTrack.rbegin() - *min_maxTrack.begin() > limit) {
                auto it = min_maxTrack.find(nums[l]);
                min_maxTrack.erase(it);
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};