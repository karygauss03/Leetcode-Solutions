class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        deque<int> mx, mn;
        int l = 0, r = 0;
        for (r = 0 ; r < nums.size() ; ++r) {
            while (!mx.empty() && nums[r] > mx.back()) {
                mx.pop_back();
            }
            mx.push_back(nums[r]);
            
            while (!mn.empty() && nums[r] < mn.back()) {
                mn.pop_back();
            }
            mn.push_back(nums[r]);
            
            if (mx.front() - mn.front() > limit) {
                if (nums[l] == mx.front()) {
                    mx.pop_front();
                }
                if (nums[l] == mn.front()) {
                    mn.pop_front();
                }
                ++l;
            }
            
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};