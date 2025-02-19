class Solution {
public:
    string getHappyString(int n, int k) {
        string currentString = "";
        vector<string> happyStrings;
        // Generate all happy strings of length n
        generateHappyStrings(n, currentString, happyStrings);

        // Check if there are at least k happy strings
        if (happyStrings.size() < k) return "";

        // Sort the happy strings in lexicographical order
        sort(happyStrings.begin(), happyStrings.end());

        return happyStrings[k - 1];
    }

private:
    void generateHappyStrings(int n, string currentString,
                              vector<string> &happyStrings) {
        // If the current string has reached the desired length, add it to the
        // list
        if (currentString.size() == n) {
            happyStrings.push_back(currentString);
            return;
        }

        // Try adding each character ('a', 'b', 'c') to the current string
        for (char currentChar = 'a'; currentChar <= 'c'; currentChar++) {
            // Skip if the current character is the same as the last character
            if (currentString.size() > 0 && currentString.back() == currentChar)
                continue;

            // Recursively generate the next character
            generateHappyStrings(n, currentString + currentChar, happyStrings);
        }
    }
};