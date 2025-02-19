class Solution {
public:
    // Check if the current sequence matches the pattern of 'I' and 'D'
    bool check(string &sequence, string &pattern) {
        for (int patternIndex = 0; patternIndex < pattern.size();
             patternIndex++) {
            if (pattern[patternIndex] == 'I') {
                // Ensure the sequence is in increasing order at 'I' positions
                if (sequence[patternIndex] > sequence[patternIndex + 1])
                    return false;
            } else {
                // Ensure the sequence is in decreasing order at 'D' positions
                if (sequence[patternIndex] < sequence[patternIndex + 1])
                    return false;
            }
        }
        return true;
    }

    string smallestNumber(string pattern) {
        int patternLength = pattern.size();
        string sequence = "";

        // Create a sequence of numbers from 1 to n+1
        for (int number = 1; number <= 1 + patternLength; number++) {
            sequence.push_back(number + '0');
        }

        string permutation = sequence;

        // Keep finding the next permutation until it matches the pattern
        while (!check(permutation, pattern)) {
            next_permutation(permutation.begin(), permutation.end());
        }

        return permutation;
    }
};