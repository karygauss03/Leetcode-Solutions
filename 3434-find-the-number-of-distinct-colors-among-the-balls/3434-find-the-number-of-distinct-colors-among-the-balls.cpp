class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int numQueries = queries.size();
        vector<int> distinctCounts(numQueries);
        unordered_map<int, int> ballColors;
        unordered_map<int, int> colorFrequency;

        for (int i = 0; i < numQueries; i++) {
            int ballIndex = queries[i][0], newColor = queries[i][1];
            if (ballColors.count(ballIndex)) {
                int previousColor = ballColors[ballIndex];
                colorFrequency[previousColor]--;
                if (colorFrequency[previousColor] == 0) {
                    colorFrequency.erase(previousColor);
                }
            }
            ballColors[ballIndex] = newColor;
            colorFrequency[newColor]++;

            distinctCounts[i] = colorFrequency.size();
        }

        return distinctCounts;
    }
};
