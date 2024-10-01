#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    const long long MOD = 1e9 + 7;
    const long long P = 701;  // A base for polynomial hashing

    // Arrays to store precomputed powers and modular inverses of P
    vector<long long> p_powers, p_inverses;

    // Precompute powers of P and their modular inverses
    void precompute_powers_and_inverses(int n) {
        p_powers.resize(n + 1);
        p_inverses.resize(n + 1);
        p_powers[0] = 1;

        // Calculate p^i mod MOD for i = 0 to n
        for (int i = 1; i <= n; ++i) {
            p_powers[i] = (p_powers[i - 1] * P) % MOD;
        }

        // Fermat's Little Theorem for calculating modular inverse of p^n mod MOD
        p_inverses[n] = modInverse(p_powers[n], MOD);
        for (int i = n - 1; i >= 0; --i) {
            p_inverses[i] = (p_inverses[i + 1] * P) % MOD;
        }
    }

    // Function to calculate modular inverse using binary exponentiation
    long long modInverse(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    // Function to calculate prefix hashes for a string
    vector<long long> precompute_hashes(const string& s) {
        int n = s.size();
        vector<long long> prefix_hashes(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix_hashes[i + 1] = (prefix_hashes[i] + (s[i] - 'a' + 1) * p_powers[i]) % MOD;
        }
        return prefix_hashes;
    }

    // Function to get the hash of a substring s[l:r+1]
    long long get_substring_hash(int l, int r, const vector<long long>& prefix_hashes) {
        long long hash_value = (prefix_hashes[r + 1] - prefix_hashes[l] + MOD) % MOD;
        return (hash_value * p_inverses[l]) % MOD;
    }

    // Function to count the number of differences between two substrings using binary splitting
    int countDifferences(int l1, int r1, int l2, int r2, const string& s, const string& pattern, const vector<long long>& shashes, const vector<long long>& phashes) {
        int differences = 0;
        vector<tuple<int, int, int, int>> stack = {{l1, r1, l2, r2}};

        while (!stack.empty()) {
            auto [left1, right1, left2, right2] = stack.back();
            stack.pop_back();

            if (left1 > right1) continue;

            // Get the hash of the current substrings
            long long s_hash = get_substring_hash(left1, right1, shashes);
            long long p_hash = get_substring_hash(left2, right2, phashes);

            // If the hashes match, skip further checking
            if (s_hash == p_hash) continue;

            // If comparing single characters, count the difference
            if (left1 == right1 && left2 == right2) {
                if (s[left1] != pattern[left2]) {
                    differences++;
                    if (differences > 1) return differences;  // Early exit
                }
                continue;
            }

            // Split the range and check both halves
            int mid1 = (left1 + right1) / 2;
            int mid2 = (left2 + right2) / 2;

            stack.push_back({left1, mid1, left2, mid2});
            stack.push_back({mid1 + 1, right1, mid2 + 1, right2});

            // Early exit if more than one difference is found
            if (differences > 1) return differences;
        }

        return differences;
    }

public:
    int minStartingIndex(string s, string pattern) {
        int n = s.size(), m = pattern.size();
        precompute_powers_and_inverses(max(n, m));

        // Precompute the prefix hashes for both s and pattern
        vector<long long> shashes = precompute_hashes(s);
        vector<long long> phashes = precompute_hashes(pattern);

        // Check every substring of s that is of length m
        for (int i = 0; i <= n - m; ++i) {
            int diff = countDifferences(i, i + m - 1, 0, m - 1, s, pattern, shashes, phashes);
            if (diff <= 1) {
                return i;
            }
        }

        return -1;  // No valid substring found
    }
};
