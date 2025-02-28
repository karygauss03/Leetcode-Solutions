class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int str1Length = str1.length();
        int str2Length = str2.length();

        vector<vector<int>> dp(str1Length + 1, vector<int>(str2Length + 1, 0));

        for (int row = 0; row <= str1Length; row++) {
            dp[row][0] = row;
        }
        for (int col = 0; col <= str2Length; col++) {
            dp[0][col] = col;
        }
        for (int row = 1; row <= str1Length; row++) {
            for (int col = 1; col <= str2Length; col++) {
                if (str1[row - 1] == str2[col - 1]) {
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                } else {
                    dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + 1;
                }
            }
        }

        string supersequence = "";
        int row = str1Length, col = str2Length;

        while (row > 0 && col > 0) {
            if (str1[row - 1] == str2[col - 1]) {
                supersequence += str1[row - 1];
                row--;
                col--;
            } else if (dp[row - 1][col] < dp[row][col - 1]) {
                supersequence += str1[row - 1];
                row--;
            } else {
                supersequence += str2[col - 1];
                col--;
            }
        }

        while (row > 0) {
            supersequence += str1[row - 1];
            row--;
        }
        while (col > 0) {
            supersequence += str2[col - 1];
            col--;
        }

        reverse(supersequence.begin(), supersequence.end());
        return supersequence;
    }
};