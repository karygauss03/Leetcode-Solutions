class Solution {
public:
    unordered_map<string, int> mp;
    vector<int> mask;
    vector<int> ans;
    
    void solve(int idx, vector<int>& mask, int m, int currentMask, vector<int>& currentAns, vector<vector<int>>& dp) {
        if (idx == mask.size()) {
            if (currentMask == ((1<<m) - 1)) {
                if (ans.size() == 0 || (currentAns.size() < ans.size())) {
                    ans = currentAns;
                }
            }
            return;
        }
        
        if (dp[idx][currentMask] != -1) {
            if (dp[idx][currentMask] <= currentAns.size()) {
                return;
            }
        }
        
        solve(idx + 1, mask, m, currentMask, currentAns, dp); // skip it
        
        // take it
        currentAns.push_back(idx);
        solve(idx + 1, mask, m, (currentMask | mask[idx]), currentAns, dp);
        
        currentAns.pop_back();
        if (currentAns.size() > 0) {
            dp[idx][currentMask] = currentAns.size();
        }

    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        for (int i = 0; i < req_skills.size(); ++i) {
            mp[req_skills[i]] = (1<<i);
        }
        
        for (int i = 0; i < people.size(); ++i) {
            int cur = 0;
            for (auto &skill : people[i]) {
                cur |= mp[skill];
            }
            mask.push_back(cur);
        }
        
        vector<vector<int>> dp(people.size(), vector<int>(1<<req_skills.size(), -1));
        vector<int> currentAns;
        
        solve(0, mask, req_skills.size(), 0, currentAns, dp);
        
        return ans;
    }
};