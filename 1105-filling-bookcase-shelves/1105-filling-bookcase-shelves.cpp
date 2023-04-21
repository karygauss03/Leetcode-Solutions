class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        if (n == 0)
            return 0;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1 ; i <= n ; ++i) {
            int currentWidth = 0;
            int currentHeight = 0;
            int k = 1;
            while (k <= i) {
                currentHeight = max(currentHeight, books[i - k][1]);
                currentWidth += books[i - k][0];
                if (currentWidth > shelfWidth) {
                    break;
                }
                dp[i] = min(dp[i], dp[i - k] + currentHeight);
                ++k;
            }
        }
        return dp[n];
    }
};


/*
1,1 2,3 2,3 1,1 1,1 1,1 1,2

(1,1)(2,3) 3
(2,3)(1,1)(1,1) 6
(1,1)(1,2)2
ANS => 11 NOT OPTIMIZED
*/