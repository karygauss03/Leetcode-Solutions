import java.util.Arrays;

class Solution {
    public int getWinner(int[] arr, int k) {
        int mx = Arrays.stream(arr).max().getAsInt();
        if (k >= arr.length) {
            return mx;
        }
        
        int currentWinner = arr[0];
        int currentStreak = 0;
        
        for (int i = 1 ; i < arr.length ; ++i) {
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
}
