int dp[105][22][105];

class Solution {
public:
    int solve(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int used, int start) {
        // cout << target << " " << " " << " " << start << endl;
        if(target == 0) {
            if(start == m) return 0;
            else return 1e9;
        }
        if(start == m) return 1e9;
        if(houses[start] == used) return 1e9;
        
        if(dp[target][used][start] != -1) return dp[target][used][start];
        
        int currcost = 0, mincost = 1e9;
        for(int color = 1; color <= n; color++) {
            currcost = 0;
            if(color == used) continue;
            for(int i = start; i < m; i++) {
                if(houses[i] != 0 and houses[i] != color) break;
                currcost += (houses[i] == 0?cost[i][color-1]:0);
                mincost = min(mincost,currcost+solve(houses,cost,m,n,target-1,color,i+1));
            }
        }
        return dp[target][used][start] = mincost;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof dp);
        int res = solve(houses,cost,m,n,target,21,0);
        if(res >= 1e9) return -1;
        return res;
    }
};