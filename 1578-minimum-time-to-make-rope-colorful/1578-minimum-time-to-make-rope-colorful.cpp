class Solution {
public:
    int dp[100006][27]; // define state as (pos , prevColor) : when prevColor !=currentColor , we have 2 choices : take currentColor or leave it! 
    int minCost(string colors, vector<int>& neededTime) {
         memset(dp,-1,sizeof(dp));
         return solve(0,26,neededTime,colors);
    }
    int solve(int pos,int prevColor,vector<int> &time,string &colors) {
         if(pos>=colors.size()) return 0;
         if(dp[pos][prevColor]!=-1) return dp[pos][prevColor];
         int cnt = 0;
         if(prevColor == colors[pos] - 'a') {
              cnt = time[pos] + solve(pos+1,prevColor,time,colors);
         }else {
              cnt = min(solve(pos+1,colors[pos]-'a',time,colors),time[pos]+solve(pos+1,prevColor,time,colors));
         }
        return dp[pos][prevColor] = cnt;
    }
};