class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for (int i = 0 ; i < l.size() ; ++i) {
            vector<int> currentSubArray(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(currentSubArray.begin(), currentSubArray.end());
            int currentDifference = currentSubArray[1] - currentSubArray[0];
            bool isArithmetic = true;
            for (int j = 1 ; j < currentSubArray.size() - 1 ; ++j) {
                if (currentDifference != currentSubArray[j + 1] - currentSubArray[j]) {
                    isArithmetic = false;
                    break;
                }
            }
            ans.push_back(isArithmetic);
        }
        return ans;
    }
};