class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> freq;
        int mxFrequency = 1;
        for (auto &num : nums) {
            freq[num]++;
            mxFrequency = max(mxFrequency, freq[num]);
        }
        
        vector<vector<int>> ans(mxFrequency);
        for (auto &f : freq) {
            while (f.second--) {
                ans[f.second].push_back(f.first);
            }
        }
        return ans;
    }
};