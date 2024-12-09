class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        int n = nums.size();
        vector<int> far(n, 0);
        int l = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                for (int j = l; j <= i - 1; ++j) {
                    far[j] = i - 1;
                }
                l = i;
            }
        }
        for (int j = l; j < n; ++j) {
            far[j] = n - 1;
        }
        for (auto& q : queries) {
            int st = q[0], nd = q[1];
            if (nd <= far[st]) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};