class Solution {
public:
    int dp[5005][2];
    int n;
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        for(int day = n + 1;day >= 0;day--){
            for(int buy = 0;buy <= 1;buy++){
                int &ans = dp[day][buy];
                if(day >= prices.size()){
                    ans = 0;
                }else{
                    // First Choice
                    int ans1 = dp[day + 1][buy]; // no transaction this say        
                    // Second Choice
                    int ans2 = 0; // doing the required transaction this day
                    if(buy){
                        ans2 = -prices[day] + dp[day + 1][0];
                    }else{
                        ans2 = prices[day] + dp[day + 2][1];
                    }
                    ans = max(ans1, ans2);
                }
            }
        }
        return dp[0][1];
    }
};