class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int rangeSize = 2 * k + 1;
        vector<int> prefix(rangeSize, 0);
        for (int i = 0; i < fruits.size(); ++i) {
            if ((fruits[i][0] < startPos-k) || (fruits[i][0] > startPos+k)) continue;
            prefix[fruits[i][0] - (startPos - k)] += fruits[i][1];
        }

        int leftSum = 0, rightSum = 0;
        for (int i = 0; i <=k; ++i) {
            leftSum += prefix[i];
            rightSum += prefix[i + k];
        }

        int ans = max(leftSum, rightSum), cnt = 1;
        for (int i = 2; i < k + 1; i += 2) {
            leftSum = leftSum + prefix[k + cnt] - prefix[i - 1] - prefix[i - 2];
            rightSum = rightSum + prefix[k - cnt] - prefix[rangeSize - i] - prefix[rangeSize - i + 1];
            ans = max({ans, leftSum, rightSum});
            ++cnt;
        }

        return ans;
    }
};