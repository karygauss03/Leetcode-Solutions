class Solution {
private:
    int dp[370];
    int solve(vector<int>& days, vector<int>& costs, int i) {
        if (i >= days.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int oneDayPass = costs[0] + solve(days, costs, i + 1);
        int j = i;
        for (j = i; j < days.size(); ++j) {
            if (days[j] >= days[i] + 7) {
                break;
            }
        }
        
        int sevenDaysPass = costs[1] + solve(days, costs, j);
        
        for (j = i; j< days.size(); ++j) {
            if (days[j] >= days[i] + 30) {
                break;
            }
        }
        
        int thirtyDaysPass = costs[2] + solve(days, costs, j);
        
        return dp[i] = min(oneDayPass, min(sevenDaysPass, thirtyDaysPass));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof dp);
        return solve(days, costs, 0);
    }
};