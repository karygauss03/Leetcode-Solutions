class Solution {
public:
    bool canChange(string start, string target) {
        int startLength = start.size();
        int startIndex = 0, targetIndex = 0;

        while (startIndex < startLength || targetIndex < startLength) {
            while (startIndex < startLength && start[startIndex] == '_') {
                startIndex++;
            }
            while (targetIndex < startLength && target[targetIndex] == '_') {
                targetIndex++;
            }
            if (startIndex == startLength || targetIndex == startLength) {
                return startIndex == startLength && targetIndex == startLength;
            }

            if (start[startIndex] != target[targetIndex] ||
                (start[startIndex] == 'L' && startIndex < targetIndex) ||
                (start[startIndex] == 'R' && startIndex > targetIndex))
                return false;

            startIndex++;
            targetIndex++;
        }

        return true;
    }
};