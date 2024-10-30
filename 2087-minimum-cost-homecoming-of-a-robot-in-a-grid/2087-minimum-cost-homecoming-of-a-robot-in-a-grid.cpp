class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans = 0;

        if (startPos[0] < homePos[0]) {
            for (int i = startPos[0] + 1; i <= homePos[0]; i++) {
                ans += rowCosts[i];
            }
        } else {
            for (int i = startPos[0] - 1; i >= homePos[0]; i--) {
                ans += rowCosts[i];
            }
        }

        if (startPos[1] < homePos[1]) {
            for (int j = startPos[1] + 1; j <= homePos[1]; j++) {
                ans += colCosts[j];
            }
        } else {
            for (int j = startPos[1] - 1; j >= homePos[1]; j--) {
                ans += colCosts[j];
            }
        }

        return ans;
    }
};
