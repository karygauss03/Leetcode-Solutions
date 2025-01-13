class Solution {
public:
    bool canBeValid(string str, string status) {
        int n = str.size();
        if (n % 2 == 1) {
            return false;
        }
        int openCount = 0, freeCount = 0;
        for (int i = 0; i < n; i++) {
            if (status[i] == '0') {
                freeCount++;
            } else if (str[i] == '(') {
                openCount++;
            } else if (str[i] == ')') {
                if (openCount > 0) {
                    openCount--;
                } else if (freeCount > 0) {
                    freeCount--;
                } else {
                    return false;
                }
            }
        }
        int netBalance = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (status[i] == '0') {
                netBalance--;
                freeCount--;
            } else if (str[i] == '(') {
                netBalance++;
                openCount--;
            } else if (str[i] == ')') {
                netBalance--;
            }
            if (netBalance > 0) {
                return false;
            }
            if (freeCount == 0 && openCount == 0) {
                break;
            }
        }
        if (openCount > 0) {
            return false;
        }
        return true;
    }
};
