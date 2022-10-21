class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int dp_increase[3][n]; //dp[i][j] : number of teams of size i and ending at jth soldier increasing order
        int dp_decrease[3][n]; //dp[i][j] : number of teams of size i and ending at jth soldier decreasing order
        memset(dp_increase, 0, sizeof dp_increase);
        memset(dp_decrease, 0, sizeof dp_decrease);
        for (int i = 0 ; i < n ; i++){
            dp_increase[0][i] = 1;
            dp_decrease[0][i] = 1;
        }
        for (int i = 1 ; i < 3 ; i++){
            for (int j = 0 ; j < n ; j++){
                for (int k = 0 ; k < j ; k++){
                    if (rating[j] > rating[k]){
                        dp_increase[i][j] += dp_increase[i - 1][k];
                    }
                    else {
                        dp_decrease[i][j] += dp_decrease[i - 1][k];
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0 ; i < n ; i++){
            ans += dp_increase[2][i] + dp_decrease[2][i];
        }
        return ans;
    }
};