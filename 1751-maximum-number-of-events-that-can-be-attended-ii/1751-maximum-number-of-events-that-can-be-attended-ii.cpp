class Solution {
private:
public:
    int solve(vector<vector<int>>& events, int k, int cur, vector<vector<int>>& dp) {
        if (cur >= events.size()) return 0;
        if (dp[cur][k] != -1) return dp[cur][k];
        int ans = solve(events, k, cur + 1, dp); // Ignoring the cur-th event and move to the next event
        if (k) {
            int nx = events.size();
            for (int i = cur + 1 ; i < events.size() ; ++i) {
                if (events[i][0] > events[cur][1]) {
                    nx = i;
                    break;
                }
            }
            ans = max(ans, events[cur][2] + solve(events, k - 1, nx, dp)); // taking the cur-th event and move to the next possible event
        }
        return dp[cur][k] = ans;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int>(k + 1, -1));;
        return solve(events, k, 0, dp);
    }
};