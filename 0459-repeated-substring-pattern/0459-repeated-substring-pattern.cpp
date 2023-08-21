class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        return (str + str).find(str, 1) < str.size();
    }
};