class Solution {
public:
    unordered_map<int, int> dp;
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0;
        for (int i = 0 ; i < arr.size() ; ++i) {
            int currentCount = 1;
            if (dp.find(arr[i] - difference) != dp.end()) {
                currentCount = 1 + dp[arr[i] - difference];
            }
            dp[arr[i]] = currentCount;
            ans = max(ans, currentCount);
        }
        return ans;
    }
};