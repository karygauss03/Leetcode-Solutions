class Solution {
private:
public:
    int solve(vector<vector<int>>& events, int k, int cur, vector<vector<int>>& dp) {
        if (cur >= events.size()) return 0;
        if (dp[cur][k] != -1) return dp[cur][k];
        int ans = solve(events, k, cur + 1, dp); // Ignoring the cur-th event and move to the next event
        if (k) {
            vector<int> temp = {events[cur][1],INT_MAX,INT_MAX};
            int nx = upper_bound(events.begin(), events.end(), temp) - events.begin();
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