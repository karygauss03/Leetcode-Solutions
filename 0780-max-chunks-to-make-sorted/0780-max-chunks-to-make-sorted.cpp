class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int curSum = 0, sum = 0, ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            curSum += arr[i];
            sum += i;
            if (curSum == sum) {
                ++ans;
            }
        }
        return ans;
    }
};