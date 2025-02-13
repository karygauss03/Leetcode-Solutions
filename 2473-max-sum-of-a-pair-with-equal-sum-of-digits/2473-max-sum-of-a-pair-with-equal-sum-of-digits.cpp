class Solution {
private:
    int calculateDigitSum(int num) {
        int digitSum = 0;
        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }
        return digitSum;
    }

public:
    int maximumSum(vector<int>& nums) {
        vector<pair<int, int>> digitSumPairs;
        for (int number : nums) {
            int digitSum = calculateDigitSum(number);
            digitSumPairs.push_back({digitSum, number});
        }
        sort(digitSumPairs.begin(), digitSumPairs.end());
        int maxPairSum = -1;
        for (int index = 1; index < digitSumPairs.size(); index++) {
            int currentDigitSum = digitSumPairs[index].first;
            int previousDigitSum = digitSumPairs[index - 1].first;
            if (currentDigitSum == previousDigitSum) {
                int currentSum = digitSumPairs[index].second +
                                 digitSumPairs[index - 1].second;
                maxPairSum = max(maxPairSum, currentSum);
            }
        }

        return maxPairSum;
    }
};