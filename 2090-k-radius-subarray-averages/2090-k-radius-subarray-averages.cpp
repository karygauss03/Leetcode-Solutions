class Solution {
public:
    vector<long long> prefixSum;
    vector<int> ans;
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0) return nums;
        prefixSum.push_back(nums[0]);
        for (int i = 1 ; i < nums.size() ; ++i){
            prefixSum.push_back(nums[i] + prefixSum.back());
        }
        
        for (int i = 0 ; i < nums.size() ; ++i){
            if (i < k || i > nums.size() - 1 - k) {
                ans.push_back(-1);
            }
            else{
                (i == k) ? ans.push_back(prefixSum[i + k] / (2 * k + 1)) : ans.push_back((prefixSum[i + k] - prefixSum[i - k - 1]) / (2 * k + 1));
            }
        }
        return ans;
    }
};