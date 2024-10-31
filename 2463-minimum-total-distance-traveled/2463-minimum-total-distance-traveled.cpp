class Solution {
private:
    long long solve(int i, int j, vector<int>& robot, vector<int>& factories, vector<vector<long long>>& dp) {
        if (i == robot.size()) {
            return 0;
        }
        if (j == factories.size()) {
            return (long long)1e13;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        // Take it?
        long long takeIt = abs(robot[i] - factories[j]) + solve(i + 1, j + 1, robot, factories, dp);
        // Skip it?
        long long skipIt = solve(i, j + 1, robot, factories, dp);
        
        return dp[i][j] = min(takeIt, skipIt);
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> factories;
        for (auto& f: factory) {
            for (int i = 0; i < f[1]; ++i) {
                factories.push_back(f[0]);
            }
        }
        int n = robot.size(), m = factories.size();
        vector<vector<long long>> dp(n, vector<long long>(m, -1));
        return solve(0, 0, robot, factories, dp);
    }
};