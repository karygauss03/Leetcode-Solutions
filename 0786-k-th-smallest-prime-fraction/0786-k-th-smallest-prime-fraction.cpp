class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0.0, right = 1.0;
        while (left < right) {
            double mid = (left + right) / 2.0;
            double maxFraction = INT_MIN, smallerFractions = 0;
            int max_i = 0, max_j = 0;
            int j = 1;
            for(int i = 0; i < n - 1; ++i) {
                while (j < n && arr[i] >= mid * arr[j]) {
                    ++j;
                }
                
                smallerFractions += (n - j);
                if (j == n) {
                    break;
                }
                
                if ((double)arr[i] / (double)arr[j] > maxFraction) {
                    max_i = i, max_j = j, maxFraction = (double)arr[i] / (double)arr[j];
                }
            }
            
            if (smallerFractions == k) {
                return {arr[max_i], arr[max_j]};
            }
            if (smallerFractions > k) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return {};
    }
};