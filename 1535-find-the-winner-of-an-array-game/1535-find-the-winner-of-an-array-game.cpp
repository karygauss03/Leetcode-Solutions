class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int mx = *max_element(arr.begin(), arr.end());
        if (k >= arr.size()) {
            return mx;
        }
        
        int currentWinner = arr[0];
        int currentStreak = 0;
        
        for (int i = 1 ; i < arr.size() ; ++i) {
            if (arr[i] <= currentWinner) {
                ++currentStreak;
            }
            else {
                currentWinner = arr[i];
                currentStreak = 1;
            }
            if (currentStreak == k || currentWinner == mx) {
                return currentWinner;
            }
        }
        return currentWinner;
    }
};