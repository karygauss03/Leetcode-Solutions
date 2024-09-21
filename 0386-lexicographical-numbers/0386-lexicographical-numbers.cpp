class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicographicalNumbers;
        for (int start = 1; start <= 9; ++start) {
            generateLexicalNumbers(start, n, lexicographicalNumbers);
        }
        return lexicographicalNumbers;
    }

private:
    void generateLexicalNumbers(int currentNumber, int limit,
                                vector<int>& result) {
        if (currentNumber > limit) return;

        result.push_back(currentNumber);
        for (int nextDigit = 0; nextDigit <= 9; ++nextDigit) {
            int nextNumber = currentNumber * 10 + nextDigit;
            if (nextNumber <= limit) {
                generateLexicalNumbers(nextNumber, limit, result);
            } else {
                break;
            }
        }
    }
};