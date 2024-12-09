class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        int n = nums.size();
        vector<int> prefix(n, 0);
        for (int i = 1; i < n; ++i) {
            if (nums[i] % 2 != nums[i - 1] % 2) {
                prefix[i] = prefix[i - 1];
            } 
            else {
                prefix[i] = prefix[i - 1] + 1;
            }
            // cout << "i: " << i << " " << prefix[i] << endl;
        }

        for (auto& q : queries) {
            if (prefix[q[1]] - prefix[q[0]] == 0) {
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};