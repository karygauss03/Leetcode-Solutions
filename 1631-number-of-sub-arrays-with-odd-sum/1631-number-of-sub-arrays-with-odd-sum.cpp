class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        // Convert elements to 0 (even) or 1 (odd)
        for (auto& num : arr) {
            num %= 2;
        }

        // dpEven[i] represents the number of subarrays with an even sum ending
        // at index i dpOdd[i] represents the number of subarrays with an odd
        // sum ending at index i
        vector<int> dpEven(n), dpOdd(n);

        // Initialization based on the last element
        // The last element is even
        if (arr[n - 1] == 0) {
            dpEven[n - 1] = 1;
        } else {
            // The last element is odd
            dpOdd[n - 1] = 1;
        }

        // Traverse the array in reverse
        for (int num = n - 2; num >= 0; num--) {
            if (arr[num] == 1) {
                // Odd element contributes to odd subarrays
                dpOdd[num] = (1 + dpEven[num + 1]) % MOD;
                // Even element continues the pattern
                dpEven[num] = dpOdd[num + 1];
            } else {
                // Even element contributes to even subarrays
                dpEven[num] = (1 + dpEven[num + 1]) % MOD;
                // Odd element continues the pattern
                dpOdd[num] = dpOdd[num + 1];
            }
        }

        // Sum all the odd subarrays
        int count = 0;
        for (auto oddCount : dpOdd) {
            count += oddCount;
            count %= MOD;
        }

        return count;
    }
};