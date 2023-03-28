class Solution {
public:
    int dp[367];
    
    int solve(vector<int>&days, vector<int>& costs, int idx){
         if(idx >= days.size()){
             return 0;
         }
        
          if(dp[idx] != -1) return dp[idx];
        
         // option 1
        
         int op1 = costs[0] + solve(days, costs, idx + 1);
         
         int k = idx;
         
         for(; k < days.size(); k++){
               if(days[k] >= days[idx] + 7) break;
         }
        
         // option 2
         int op2 = costs[1] + solve(days, costs, k);
        
         for(; k < days.size(); k++){
             if(days[k] >= days[idx] + 30) break;
         }
        
         int op3 = costs[2] + solve(days, costs, k);
        
         return dp[idx] = min(op1, min(op2,op3));
    
     }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
          memset(dp, -1, sizeof(dp));
          return solve(days,costs,0);
    }
};