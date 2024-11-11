class Solution {
private:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        // Generate all primes less than 1000
        vector<int> primes;
        for (int i = 2; i < 1000; ++i) {
            if (isPrime(i)) {
                primes.push_back(i);
            }
        }

        int prev = -1;  // To track the previous element in the array after the operation

        // Traverse each element in nums
        for (int i = 0; i < nums.size(); ++i) {
            int cur = nums[i];  // Current element of nums
            if (cur <= prev) {
                return false;  // If current element is not greater than the previous one, return false
            }

            // Use binary search to find the largest prime less than `cur` that also keeps `cur` greater than `prev`
            int l = 0, r = primes.size() - 1;
            int bestPrime = 0;

            while (l <= r) {
                int mid = (l + r) / 2;
                if (primes[mid] < cur && (cur - primes[mid] > prev)) {
                    bestPrime = primes[mid];  // Update the best prime found
                    l = mid + 1;  // Search in the right half for a potentially larger prime
                } else {
                    r = mid - 1;  // Search in the left half
                }
            }

            // Subtract the bestPrime if found
            if (bestPrime > 0) {
                cur -= bestPrime;
            }

            // Update `prev` to be the modified `cur`
            prev = cur;
        }
        return true;
    }
};
