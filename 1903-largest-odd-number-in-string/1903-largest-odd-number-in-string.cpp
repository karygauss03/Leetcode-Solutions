class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size() - 1;
        while (i >= 0) {
            if ((num[i] - '0') & 1) {
                return num.substr(0, i + 1);
            }
            --i;
        }
        return "";
    }
};