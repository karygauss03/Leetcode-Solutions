class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // dp[i] longest increasing sequence with length i+1, vector of pair for different ending number as {ending number, count}
        // dp[i][:] has a decreasing ending number, and increasing count number
        // dp[:] of above ending number is increasing 
        if(nums.empty()) return 0; 

        vector<vector<pair<int,int>>> dp(nums.size()+1); 
        int max_len = 0; 
        auto outerCheck = [](vector<pair<int, int>>& vp, int nn){return !vp.empty() && vp.back().first < nn;};  // ascending vector use <
        auto innerCheck = [](int nn, pair<int, int>& p){return nn > p.first;};  // descending vector use >

        for(auto n: nums) {
            int out_id = lower_bound(begin(dp), end(dp), n, outerCheck) - dp.begin(); 

            int options = 1; 
            int preList = out_id - 1; 
            if(preList >= 0) {
                int in_id = upper_bound(begin(dp[preList]), end(dp[preList]), n, innerCheck) - dp[preList].begin(); 

                options = dp[preList].back().second; 
                options -= in_id == 0 ? 0 : dp[preList][in_id-1].second; 
            }    

            dp[out_id].push_back({n, dp[out_id].size() == 0 ? options : dp[out_id].back().second + options} ); 
            if(out_id == max_len) 
                max_len++; 
        }
        return dp[max_len-1].back().second; 
    }
};