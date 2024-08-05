class Solution {
private:
    bool isSameParity(char a, char b) {
        return ((a - '0') & 1) == ((b - '0') & 1);
    }
public:
    string getSmallestString(string s) {
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] > s[i + 1] && isSameParity(s[i], s[i + 1])) {
                swap(s[i], s[i + 1]);
                return s;
            }
        }
        return s;
    }
};